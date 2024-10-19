#include "ThreadManager.h"
#include <iostream>

std::mutex consoleMutex; // Mutex to synchronize console output

// Function that manages the simulation and output for one entity
void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode, int entityId, std::string entityType)
{
    std::lock_guard<std::mutex> lock(consoleMutex); // Lock the console output for this entity's thread
    std::cout << "Entity: " << entityType << " " << entityId << " - Start Node: " << startNode->getId() << " Goal Node: " << goalNode->getId() << std::endl;

    // Perform pathfinding for this entity
    std::vector<Node *> path = pathfindingManager.findPath(startNode, goalNode, entityType, entityId);

    if (path.empty())
    {
        std::cout << "Entity: " << entityType << " " << entityId << " - No path found." << std::endl;
    }
    else
    {
        std::cout << "Entity: " << entityType << " " << entityId << " - Path found:" << std::endl;
        for (Node *node : path)
        {
            std::cout << "Node ID: " << node->getId() << " at (" << node->getX() << ", " << node->getY() << ", " << node->getZ() << ")" << std::endl;
        }
    }
}

// Function to run the simulation in a multithreaded environment
void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager, int npcCount, int vehicleCount)
{
    std::vector<std::thread> threads;

    // Create threads for NPCs
    for (int i = 0; i < npcCount; ++i)
    {
        std::shared_ptr<Node> startNode = nodeManager.getNodes()[i];
        std::shared_ptr<Node> goalNode = nodeManager.getNodes()[99]; // Example goal node
        threads.push_back(std::thread(entityThreadFunction, std::ref(trafficManager), std::ref(pathfindingManager), startNode, goalNode, i + 1, "NPC"));
    }

    // Create threads for Vehicles
    for (int i = 0; i < vehicleCount; ++i)
    {
        std::shared_ptr<Node> startNode = nodeManager.getNodes()[i];
        std::shared_ptr<Node> goalNode = nodeManager.getNodes()[99]; // Example goal node
        threads.push_back(std::thread(entityThreadFunction, std::ref(trafficManager), std::ref(pathfindingManager), startNode, goalNode, i + 1, "Vehicle"));
    }

    // Wait for all threads to finish
    for (auto &th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}