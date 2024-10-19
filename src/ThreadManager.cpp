#include "ThreadManager.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <condition_variable>
#include <atomic>
#include <queue>

std::mutex consoleMutex;
std::mutex messageMutex;
std::queue<std::string> pathfindingLogs; // Queue for storing logs
std::condition_variable cv;
std::atomic<bool> barCompletionFlag(false);

// Queue to store console messages
std::queue<std::string> messageQueue;

// Function to safely add messages to the messageQueue
void addMessageToQueue(const std::string &message)
{
    std::lock_guard<std::mutex> lock(messageMutex);
    messageQueue.push(message);
}

// Thread-safe console print function
void printMessagesFromQueue()
{
    while (!barCompletionFlag || !messageQueue.empty()) // Only start after bars complete
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        if (!messageQueue.empty())
        {
            std::cout << messageQueue.front() << std::endl;
            messageQueue.pop();
        }
    }
}

// Simulated progress bar movement
void showProgressBars(const std::vector<ProgressBar> &bars, std::mutex &progressMutex)
{
    std::lock_guard<std::mutex> lock(progressMutex);
    // Move cursor up to overwrite previous bars, keeping only one set of progress bars
    std::cout << "\033[H"; // Moves cursor to the top of the screen (instead of clearing)
    for (const auto &bar : bars)
    {
        std::cout << "\033[34m" << bar.entityType << " " << bar.entityId << ": [";
        int pos = 50 * bar.progress;
        for (int j = 0; j < 50; ++j)
        {
            if (j < pos)
                std::cout << "=";
            else if (j == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
        std::cout << "] " << int(bar.progress * 100.0) << "%\033[0m\r\n";
    }
    std::cout.flush(); // Flush output buffer to ensure immediate printing
}

// Entity movement and pathfinding simulation
void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                          std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode,
                          ProgressBar &progressBar, std::atomic<int> &activeEntities, std::mutex &progressMutex)
{
    float progress = 0.0f;
    while (progress <= 1.0f)
    {
        {
            std::lock_guard<std::mutex> lock(progressMutex); // Lock for progress update
            progressBar.progress = progress;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Smooth progress update
        progress += 0.05f;
    }

    // Finalize the progress bar
    {
        std::lock_guard<std::mutex> lock(progressMutex);
        progressBar.progress = 1.0f;
    }

    // Perform pathfinding (logs are stored but not printed during simulation)
    std::vector<Node *> path = pathfindingManager.findPath(startNode, goalNode, progressBar.entityType, progressBar.entityId);
    bool success = !path.empty();

    // Add result to message queue for logging (not printed immediately)
    addMessageToQueue(progressBar.entityType + " " + std::to_string(progressBar.entityId) +
                      (success ? ": Path found!" : ": No path found."));

    --activeEntities; // Decrement the active entity count
}

// Periodically update the progress bars
void updateProgressBars(const std::vector<ProgressBar> &bars, std::atomic<int> &activeEntities, std::mutex &progressMutex)
{
    while (activeEntities > 0)
    {
        showProgressBars(bars, progressMutex);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Update frequency
    }
    // Final update of the bars
    showProgressBars(bars, progressMutex);
    barCompletionFlag = true; // Notify that bars are done
}

// Dedicated message queue processor for logs after bars finish
void processMessageQueue()
{
    // Wait until progress bars are completed before starting log printing
    std::unique_lock<std::mutex> lock(consoleMutex);
    cv.wait(lock, []
            { return barCompletionFlag.load(); });

    // Print all queued messages (pathfinding results)
    while (!messageQueue.empty())
    {
        std::lock_guard<std::mutex> messageLock(messageMutex);
        std::cout << messageQueue.front() << std::endl;
        messageQueue.pop();
    }
}

// Thread-safe function to store logs
void storeLog(const std::string &message)
{
    std::lock_guard<std::mutex> lock(consoleMutex);
    pathfindingLogs.push(message);
}

// Function to run the simulation with progress bars and log collection
void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                                std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles,
                                NodeManager &nodeManager, int npcCount, int vehicleCount, std::atomic<bool> &nodesReady)
{
    std::mutex progressMutex; // Synchronization for progress bars
    std::vector<std::thread> threads;
    std::atomic<int> activeEntities(npcCount + vehicleCount);
    std::vector<ProgressBar> progressBars;

    // Create progress bars for NPCs and Vehicles
    for (int i = 0; i < npcCount; ++i)
    {
        progressBars.push_back({"NPC", npcs[i].getId(), 0.0f});
    }
    for (int i = 0; i < vehicleCount; ++i)
    {
        progressBars.push_back({"Vehicle", vehicles[i].getId(), 0.0f});
    }

    // Wait until nodes are ready
    while (!nodesReady)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // Thread to show progress bars
    std::thread progressBarThread([&]()
                                  { updateProgressBars(progressBars, activeEntities, progressMutex); });

    // Launch threads for each NPC and Vehicle to run the simulation and store logs
    for (int i = 0; i < npcCount; ++i)
    {
        threads.emplace_back([&, i]
                             { entityThreadFunction(trafficManager, pathfindingManager, npcs[i].getCurrentNode(),
                                                    nodeManager.getGoalNode(), progressBars[i], activeEntities, progressMutex); });
    }

    for (int i = 0; i < vehicleCount; ++i)
    {
        threads.emplace_back([&, i]
                             { entityThreadFunction(trafficManager, pathfindingManager, vehicles[i].getCurrentNode(),
                                                    nodeManager.getGoalNode(), progressBars[npcCount + i], activeEntities, progressMutex); });
    }

    // Wait for all threads to finish
    for (auto &thread : threads)
    {
        thread.join();
    }

    // Ensure progress bars hit 100% before stopping the thread
    progressBarThread.join();

    // Prompt user to print logs once
    std::cout << "Progress bars completed. Would you like to print the output logs? (y/n): ";
    char userInput;
    std::cin >> userInput;

    if (userInput == 'y' || userInput == 'Y')
    {
        std::cout << "\nPrinting logs:\n";
        while (!pathfindingLogs.empty())
        {
            std::cout << pathfindingLogs.front() << std::endl;
            pathfindingLogs.pop();
        }
    }
    else
    {
        std::cout << "Skipping log output.\n";
    }
}
