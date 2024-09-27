#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

#include "Entity.h" // Include the base Entity class
#include <vector>
#include <memory> // For std::shared_ptr

class TrafficManager
{
private:
    std::vector<std::shared_ptr<Entity>> entities; // Unified container for all entities

public:
    // Add any entity (NPC, Vehicle, etc.) to the manager
    void addEntity(std::shared_ptr<Entity> entity);

    // Update all entities (e.g., NPCs and Vehicles)
    void updateEntities();
};

#endif // TRAFFICMANAGER_H
