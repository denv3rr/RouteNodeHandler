#include "../include/simulation.h"
#include "../include/NPC.h"
#include "../include/Vehicle.h"
#include <iostream>

// Initialize NPCs and store them as Entities
void initializeNPCs(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<std::shared_ptr<Entity>> &entities, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        auto npc = std::make_shared<NPC>(i + 1, nodes[randomNodeIndex].get()); // Create NPC as a shared_ptr
        entities.push_back(npc);                                               // Store NPC in entities container
        trafficManager.addEntity(npc);                                         // Assuming trafficManager has a generic addEntity function now
    }
}

// Initialize Vehicles and store them as Entities
void initializeVehicles(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<std::shared_ptr<Entity>> &entities, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int randomNodeIndex = std::rand() % nodes.size();
        auto vehicle = std::make_shared<Vehicle>(i + 1, nodes[randomNodeIndex].get()); // Create Vehicle as a shared_ptr
        entities.push_back(vehicle);                                                   // Store Vehicle in entities container
        trafficManager.addEntity(vehicle);                                             // Assuming trafficManager has a generic addEntity function now
    }
}

// Run the traffic simulation loop for all entities
void simulateTraffic(TrafficManager &trafficManager, std::vector<std::shared_ptr<Entity>> &entities)
{
    std::cout << "Simulating traffic...\n"
              << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Step " << i + 1 << ":\n";
        for (auto &entity : entities)
        {
            entity->move(); // Call move on all entities (NPCs and Vehicles)
        }
        trafficManager.updateEntities(); // Assuming TrafficManager now works with generic entities
    }
}
