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
void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager, PathfindingManager &pathfindingManager)
{
    std::cout << "\n\033[32mSimulating traffic...\033[0m\n"
              << std::endl;

    // Set up the pathfinding algorithm (can be A*, Dijkstra, etc.)
    pathfindingManager.setAlgorithm(std::make_shared<AStarPathfinder>());

    // Assign a path to all NPCs and Vehicles
    for (NPC &npc : npcs)
    {
        std::shared_ptr<Node> startNode = nodeManager.getNodes()[0]; // Example start node
        std::shared_ptr<Node> endNode = nodeManager.getNodes()[99];  // Example end node

        // Recalculate path dynamically based on node status
        npc.setPath(pathfindingManager.findPath(startNode, endNode));
    }

    for (Vehicle &vehicle : vehicles)
    {
        std::shared_ptr<Node> startNode = nodeManager.getNodes()[0]; // Example start node
        std::shared_ptr<Node> endNode = nodeManager.getNodes()[99];  // Example end node

        // Recalculate path dynamically based on node status
        vehicle.setPath(pathfindingManager.findPath(startNode, endNode));
    }

    // Simulate traffic and adjust paths dynamically if conditions change
    for (int i = 0; i < 10; ++i)
    {
        // During each update, check for changes (e.g., blocked nodes) and update paths accordingly
        for (NPC &npc : npcs)
        {
            std::shared_ptr<Node> currentNode = std::make_shared<Node>(*npc.getCurrentNode());
            if (currentNode->isBlocked())
            {
                // Recalculate path if the current node becomes blocked
                std::shared_ptr<Node> newEndNode = nodeManager.getNodes()[99]; // Pick another end node if needed
                npc.setPath(pathfindingManager.findPath(currentNode, newEndNode));
            }
        }

        for (Vehicle &vehicle : vehicles)
        {
            std::shared_ptr<Node> currentNode = std::make_shared<Node>(*vehicle.getCurrentNode());
            ;
            if (currentNode->isBlocked())
            {
                // Recalculate path if the current node becomes blocked
                std::shared_ptr<Node> newEndNode = nodeManager.getNodes()[99]; // Pick another end node if needed
                vehicle.setPath(pathfindingManager.findPath(currentNode, newEndNode));
            }
        }

        trafficManager.updateEntities(); // Move all entities along their paths
    }
}
