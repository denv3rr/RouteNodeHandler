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
void showProgressBars(const std::vector<ProgressBar> &bars)
{
    std::lock_guard<std::mutex> lock(consoleMutex);
    // Clear the screen before printing the bars
    std::cout << "\033[2J\033[H"; // Clear screen and move cursor to top
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
                          ProgressBar &progressBar, std::atomic<int> &activeEntities)
{
    float progress = 0.0f;
    while (progress <= 1.0f)
    {
        {
            // Lock only during progress update
            std::lock_guard<std::mutex> lock(consoleMutex);
            progressBar.progress = progress;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Smooth progress update
        progress += 0.05f;
    }

    // Finalize the progress bar
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        progressBar.progress = 1.0f;
    }

    // Perform pathfinding
    std::vector<Node *> path = pathfindingManager.findPath(startNode, goalNode, progressBar.entityType, progressBar.entityId);
    bool success = !path.empty();

    // Add result to message queue for logging
    addMessageToQueue(progressBar.entityType + " " + std::to_string(progressBar.entityId) +
                      (success ? ": Path found!" : ": No path found."));

    --activeEntities; // Decrement the active entity count
}

// Periodically update the progress bars
void updateProgressBars(const std::vector<ProgressBar> &bars, std::atomic<int> &activeEntities)
{
    while (activeEntities > 0)
    {
        showProgressBars(bars);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Update frequency
    }
    // Final update of the bars
    showProgressBars(bars);
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

void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                                std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles,
                                NodeManager &nodeManager, int npcCount, int vehicleCount, std::atomic<bool> &nodesReady)
{
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

    // Ensure no thread starts until node generation is complete
    while (!nodesReady)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Wait until nodes are ready
    }

    // Start progress bars in a separate thread
    std::thread progressBarThread([&]()
                                  {
        while (activeEntities > 0)
        {
            showProgressBars(progressBars);  // Show progress for all entities
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Smooth update
        }
        showProgressBars(progressBars);  // Ensure all bars hit 100%
        barCompletionFlag = true; });

    // Launch threads for each NPC and Vehicle
    for (int i = 0; i < npcCount; ++i)
    {
        threads.emplace_back([&, i]
                             { entityThreadFunction(trafficManager, pathfindingManager, npcs[i].getCurrentNode(),
                                                    nodeManager.getGoalNode(), progressBars[i], activeEntities); });
    }

    for (int i = 0; i < vehicleCount; ++i)
    {
        threads.emplace_back([&, i]
                             { entityThreadFunction(trafficManager, pathfindingManager, vehicles[i].getCurrentNode(),
                                                    nodeManager.getGoalNode(), progressBars[npcCount + i], activeEntities); });
    }

    // Wait for all threads to finish
    for (auto &thread : threads)
    {
        thread.join();
    }

    // Ensure progress bars hit 100% before stopping the thread
    progressBarThread.join();
    cv.notify_all(); // Notify the condition variable to allow message printing

    // Signal completion of progress bar and allow logging
    std::cout << "\033[32mProgress bars completed.\033[0m Generating output logs...\n";
}
