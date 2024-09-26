#include "../include/simulation.h"
#include "../include/NPC.h"
#include "../include/Vehicle.h"
#include <iostream>

// Initialize NPCs by placing them on random nodes
void initializeNPCs(TrafficManager &trafficManager, const std::vector<Node> &nodes, std::vector<NPC> &npcs, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        npcs.emplace_back(i + 1, const_cast<Node *>(&nodes[randomNodeIndex])); // Create an NPC with a random starting node
        trafficManager.addNPC(&npcs.back());
    }
}

// Initialize Vehicles in a similar manner as NPCs
void initializeVehicles(TrafficManager &trafficManager, const std::vector<Node> &nodes, std::vector<Vehicle> &vehicles, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        vehicles.emplace_back(i + 1, const_cast<Node *>(&nodes[randomNodeIndex])); // Create a Vehicle with a random starting node
        trafficManager.addVehicle(&vehicles.back());
    }
}

// Run the traffic simulation loop
void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles)
{
    std::cout << "Simulating traffic...\n"
              << std::endl;
    for (int i = 0; i < 10; ++i)
    {                                    // For demonstration, run 10 simulation steps
        trafficManager.updateEntities(); // Move all entities
    }
}
