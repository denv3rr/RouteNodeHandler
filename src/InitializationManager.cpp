#include "../include/InitializationManager.h"
#include <iostream>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds

// Function to display a progress bar
void printProgressBar(float progress, int width = 50)
{
    std::cout << "[";
    int pos = width * progress;
    for (int i = 0; i < width; ++i)
    {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
}

void initializeNPCs(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<NPC> &npcs, int numNPCs)
{
    for (int i = 0; i < numNPCs; ++i)
    {
        // Create NPCs with id and starting node
        int randomNodeIndex = std::rand() % nodes.size();
        NPC npc(i, nodes[randomNodeIndex].get());
        npcs.push_back(npc);
        trafficManager.addEntity(std::make_shared<NPC>(npc));

        // Update progress bar
        float progress = (float)(i + 1) / numNPCs;
        printProgressBar(progress);

        // Simulate workload
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << std::endl; // Move to next line after progress bar completes
}

void initializeVehicles(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<Vehicle> &vehicles, int numVehicles)
{
    for (int i = 0; i < numVehicles; ++i)
    {
        // Create Vehicles with id and starting node
        int randomNodeIndex = std::rand() % nodes.size();
        Vehicle vehicle(i, nodes[randomNodeIndex].get());
        vehicles.push_back(vehicle);
        trafficManager.addEntity(std::make_shared<Vehicle>(vehicle));

        // Update progress bar
        float progress = (float)(i + 1) / numVehicles;
        printProgressBar(progress);

        // Simulate workload
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << std::endl; // Move to next line after progress bar completes
}
