#include "ThreadManager.h"
#include <iostream>
#include <mutex>

std::mutex consoleMutex; // Mutex to synchronize console output

// Function that manages the simulation and output for one entity
void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode, int entityId, std::string entityType)
{
    {
        std::lock_guard<std::mutex> lock(consoleMutex); // Lock console output for progress and results
        std::cout << "Entity: " << entityType << " " << entityId << " - Start Node: " << startNode->getId() << " Goal Node: " << goalNode->getId() << std::endl;
    }

    // Perform pathfinding for this entity
    std::vector<Node *> path = pathfindingManager.findPath(startNode, goalNode, entityType, entityId);

    {
        std::lock_guard<std::mutex> lock(consoleMutex); // Lock console output for results
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
}

void showProgressWithEntity(const std::string &entityType, int entityId, float progress)
{
    std::lock_guard<std::mutex> lock(consoleMutex); // Lock the output for progress bar
    std::cout << "\033[34m" << entityType << " " << entityId << ": [";
    int pos = 50 * progress;
    for (int i = 0; i < 50; ++i)
    {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << "%\033[0m\r";
    std::cout.flush();
}

// Function to run the simulation in a multithreaded environment
void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager, int npcCount, int vehicleCount)
{
    std::vector<std::thread> threads;

    // Process NPCs
    for (int i = 0; i < npcCount; ++i)
    {
        threads.push_back(std::thread([&, i]()
                                      {
                                          NPC &npc = npcs[i];
                                          float progress = 0.0f;
                                          while (progress <= 1.0f)
                                          {
                                              showProgressWithEntity("NPC", npc.getId(), progress);
                                              std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                              progress += 0.1f;
                                          }
                                          std::vector<Node *> path = pathfindingManager.findPath(npc.getCurrentNode(), nodeManager.getGoalNode(), "NPC", npc.getId());
                                          bool success = !path.empty();
                                          displayEntityStatus("NPC", npc.getId(), success, "Pathfinding complete.");
                                          if (success)
                                              npc.setPath(path); // Assign the found path to the NPC
                                      }));
    }

    // Process Vehicles
    for (int i = 0; i < vehicleCount; ++i)
    {
        threads.push_back(std::thread([&, i]()
                                      {
                                          Vehicle &vehicle = vehicles[i];
                                          float progress = 0.0f;
                                          while (progress <= 1.0f)
                                          {
                                              showProgressWithEntity("Vehicle", vehicle.getId(), progress);
                                              std::this_thread::sleep_for(std::chrono::milliseconds(100));
                                              progress += 0.1f;
                                          }
                                          std::vector<Node *> path = pathfindingManager.findPath(vehicle.getCurrentNode(), nodeManager.getGoalNode(), "Vehicle", vehicle.getId());
                                          bool success = !path.empty();
                                          displayEntityStatus("Vehicle", vehicle.getId(), success, "Pathfinding complete.");
                                          if (success)
                                              vehicle.setPath(path); // Assign the found path to the vehicle
                                      }));
    }

    // Wait for all threads to complete
    for (auto &thread : threads)
    {
        if (thread.joinable())
            thread.join();
    }
}
