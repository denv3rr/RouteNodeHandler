#include "../include/simulation.h"
#include "../include/NPC.h"
#include "../include/Vehicle.h"
#include "../include/NodeManager.h"
#include <iostream>
#include <memory> // For std::shared_ptr

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
void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager)
{
    std::cout << "\n\033[32mSimulating traffic...\033[0m\n"
              << std::endl;

    // Assign a simple path to all NPCs and Vehicles
    for (NPC &npc : npcs)
    {
        std::shared_ptr<Node> startNode = nodeManager.getNodes()[0]; // Example start node
        std::shared_ptr<Node> endNode = nodeManager.getNodes()[99];  // Example end node

        npc.setPath(nodeManager.findPath(startNode, endNode)); // Set the path for NPC
    }

    for (Vehicle &vehicle : vehicles)
    {
        std::shared_ptr<Node> startNode = nodeManager.getNodes()[0]; // Example start node
        std::shared_ptr<Node> endNode = nodeManager.getNodes()[99];  // Example end node

        vehicle.setPath(nodeManager.findPath(startNode, endNode)); // Set the path for Vehicle
    }

    for (int i = 0; i < 10; ++i)
    {
        trafficManager.updateEntities(); // Move all entities along their paths
    }
}
