#include "../include/InitializationManager.h"
#include <iostream>
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::milliseconds
#include <iomanip> // For std::setprecision

// Function to show progress for each entity (NPC or Vehicle)
void showProgress(const std::string &entityType, int id, bool pathFound)
{
    std::string bar = "[";
    for (int i = 0; i <= 50; i++)
    {
        bar += "=";
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Simulate work
        std::cout << "\r" << bar << "] " << std::setw(3) << (i * 2) << "%";
        std::cout.flush();
    }
    std::cout << "\n";

    // Show color-coded result
    if (pathFound)
    {
        std::cout << "\033[32m" << entityType << " " << id << ": Path found!\033[0m\n";
    }
    else
    {
        std::cout << "\033[31m" << entityType << " " << id << ": No path found.\033[0m\n";
    }
}

// Displays the status of the entity after a pathfinding attempt
void displayEntityStatus(const std::string &entityType, int entityId, bool success, const std::string &status)
{
    if (success)
    {
        std::cout << "\033[32m" << entityType << " " << entityId << ": " << status << " Path found!\033[0m\n";
    }
    else
    {
        std::cout << "\033[31m" << entityType << " " << entityId << ": " << status << " No path found.\033[0m\n";
    }
}

void initializeNPCs(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<NPC> &npcs, int numNPCs)
{
    for (int i = 0; i < numNPCs; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        NPC npc(i, nodes[randomNodeIndex]); // Pass the shared_ptr directly
        trafficManager.addEntity(std::make_shared<NPC>(npc));
        npcs.push_back(npc);
    }
}

void initializeVehicles(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<Vehicle> &vehicles, int numVehicles)
{
    for (int i = 0; i < numVehicles; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        Vehicle vehicle(i, nodes[randomNodeIndex]); // Pass the shared_ptr directly
        trafficManager.addEntity(std::make_shared<Vehicle>(vehicle));
        vehicles.push_back(vehicle);
    }
}
