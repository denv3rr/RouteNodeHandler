#include "ThreadManager.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic>

std::mutex consoleMutex;         // Mutex for console logging
std::atomic<int> activeEntities; // Track remaining active entities

// Function to safely log messages to the console
void logMessage(const std::string &message)
{
    std::lock_guard<std::mutex> lock(consoleMutex);
    std::cout << message << std::endl;
}

// Function to show the progress bar for a single entity
void showSingleProgressBar(const ProgressBar &bar)
{
    std::lock_guard<std::mutex> lock(consoleMutex);
    std::cout << bar.entityType << " " << bar.entityId << ": [";
    int pos = static_cast<int>(50 * bar.progress);
    for (int j = 0; j < 50; ++j)
    {
        if (j < pos)
            std::cout << "=";
        else if (j == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(bar.progress * 100.0) << "%\n";
    std::cout.flush();
}

// Thread function to simulate progress for each entity one at a time
void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                          std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode,
                          ProgressBar &progressBar)
{
    float progress = 0.0f;

    while (progress <= 1.0f)
    {
        progressBar.progress = progress;
        showSingleProgressBar(progressBar);                          // Display progress bar for this entity
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate progress
        progress += 0.05f;                                           // Increment progress
    }

    // Perform pathfinding (simulated)
    std::vector<Node *> path = pathfindingManager.findPath(startNode, goalNode, progressBar.entityType, progressBar.entityId);
    bool success = !path.empty();

    logMessage(progressBar.entityType + " " + std::to_string(progressBar.entityId) + ": Path " + (success ? "found" : "not found"));

    // Decrement active entities
    activeEntities.fetch_sub(1, std::memory_order_relaxed);
}

// Progress bar update loop to show each entity's progress one at a time
void updateProgressBars(std::vector<ProgressBar> &bars)
{
    for (auto &bar : bars)
    {
        while (bar.progress < 1.0f)
        {
            showSingleProgressBar(bar);
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Refresh rate
        }
    }
    logMessage("\nProgress bars completed. No more active entities.");
}

// Main multithreaded simulation function
void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                                std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles,
                                NodeManager &nodeManager, int npcCount, int vehicleCount, std::atomic<bool> &nodesReady)
{
    std::vector<std::thread> threads;
    std::vector<ProgressBar> progressBars;

    // Prepare progress bars for NPCs and Vehicles
    for (int i = 0; i < npcCount; ++i)
    {
        progressBars.push_back({"NPC", npcs[i].getId(), 0.0f});
    }
    for (int i = 0; i < vehicleCount; ++i)
    {
        progressBars.push_back({"Vehicle", vehicles[i].getId(), 0.0f});
    }

    activeEntities.store(npcCount + vehicleCount); // Set the total number of entities

    // Wait until nodes are ready
    while (!nodesReady)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // Launch threads for each NPC
    for (int i = 0; i < npcCount; ++i)
    {
        threads.emplace_back([&, i]()
                             {
            logMessage("NPC " + std::to_string(i) + " starting pathfinding...");
            entityThreadFunction(trafficManager, pathfindingManager, npcs[i].getCurrentNode(),
                                 nodeManager.getGoalNode(), progressBars[i]); });
    }

    // Launch threads for each Vehicle
    for (int i = 0; i < vehicleCount; ++i)
    {
        threads.emplace_back([&, i]()
                             {
            logMessage("Vehicle " + std::to_string(i) + " starting pathfinding...");
            entityThreadFunction(trafficManager, pathfindingManager, vehicles[i].getCurrentNode(),
                                 nodeManager.getGoalNode(), progressBars[npcCount + i]); });
    }

    // Sequentially update progress bars one at a time
    std::thread progressBarThread([&]()
                                  { updateProgressBars(progressBars); });

    // Wait for all entity threads to finish
    for (auto &thread : threads)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }

    // Wait for progress bar update thread to finish
    if (progressBarThread.joinable())
    {
        progressBarThread.join();
    }

    logMessage("All threads completed, and progress bar thread joined.");
}
