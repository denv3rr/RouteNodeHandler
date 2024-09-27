#include "../include/simulation.h"
#include "../include/NPC.h"
#include "../include/Vehicle.h"
#include <iostream>

// Initialize NPCs and add them as entities
void initializeNPCs(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<NPC> &npcs, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        auto npc = std::make_shared<NPC>(i + 1, nodes[randomNodeIndex].get()); // Create NPC
        npcs.push_back(*npc);                                                  // Add to NPCs vector
        trafficManager.addEntity(npc);                                         // Add to traffic manager as an entity
    }
}

// Initialize Vehicles and add them as entities
void initializeVehicles(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<Vehicle> &vehicles, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        auto vehicle = std::make_shared<Vehicle>(i + 1, nodes[randomNodeIndex].get()); // Create Vehicle
        vehicles.push_back(*vehicle);                                                  // Add to Vehicles vector
        trafficManager.addEntity(vehicle);                                             // Add to traffic manager as an entity
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
