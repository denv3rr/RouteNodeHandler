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
    while (!messageQueue.empty())
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
    std::cout << "\033[H";
    for (size_t i = 0; i < bars.size(); ++i)
    {
        std::cout << "\033[34m" << bars[i].entityType << " " << bars[i].entityId << ": [";
        int pos = 50 * bars[i].progress;
        for (int j = 0; j < 50; ++j)
        {
            if (j < pos)
                std::cout << "=";
            else if (j == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
        std::cout << "] " << int(bars[i].progress * 100.0) << "%\033[0m\r\n";
    }
    std::cout.flush();
}

// Entity movement and pathfinding simulation
void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                          std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode,
                          ProgressBar &progressBar, std::atomic<int> &activeEntities,
                          std::condition_variable &cv)
{
    float progress = 0.0f;
    while (progress <= 1.0f)
    {
        progressBar.progress = progress;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        progress += 0.1f;
    }

    // Perform pathfinding
    std::vector<Node *> path = pathfindingManager.findPath(startNode, goalNode, progressBar.entityType, progressBar.entityId);
    bool success = !path.empty();

    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        addMessageToQueue("Using Dijkstra's algorithm...");
        addMessageToQueue(progressBar.entityType + " " + std::to_string(progressBar.entityId) +
                          (success ? ": Path found!" : ": No path found."));
    }

    --activeEntities;
    cv.notify_all();
}

// Periodically update the progress bars
void updateProgressBars(const std::vector<ProgressBar> &bars, std::atomic<int> &activeEntities)
{
    while (activeEntities > 0)
    {
        showProgressBars(bars);
        printMessagesFromQueue();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                                std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles,
                                NodeManager &nodeManager, int npcCount, int vehicleCount)
{
    std::vector<std::thread> threads;
    std::vector<ProgressBar> progressBars;
    std::atomic<int> activeEntities(npcCount + vehicleCount);
    std::condition_variable cv;

    // Create progress bars for NPCs and Vehicles
    for (int i = 0; i < npcCount; ++i)
    {
        progressBars.push_back({"NPC", npcs[i].getId(), 0.0f});
    }
    for (int i = 0; i < vehicleCount; ++i)
    {
        progressBars.push_back({"Vehicle", vehicles[i].getId(), 0.0f});
    }

    // Start progress bar update thread
    std::thread progressBarThread(updateProgressBars, std::ref(progressBars), std::ref(activeEntities));

    // Launch threads for NPCs and Vehicles
    for (int i = 0; i < npcCount; ++i)
    {
        threads.emplace_back([&, i]()
                             { entityThreadFunction(trafficManager, pathfindingManager, npcs[i].getCurrentNode(),
                                                    nodeManager.getGoalNode(), progressBars[i], activeEntities, cv); });
    }

    for (int i = 0; i < vehicleCount; ++i)
    {
        threads.emplace_back([&, i]()
                             { entityThreadFunction(trafficManager, pathfindingManager, vehicles[i].getCurrentNode(),
                                                    nodeManager.getGoalNode(), progressBars[npcCount + i], activeEntities, cv); });
    }

    // Wait for all threads to finish
    for (auto &thread : threads)
    {
        if (thread.joinable())
            thread.join();
    }

    // Ensure the progress bar thread completes
    progressBarThread.join();
}
