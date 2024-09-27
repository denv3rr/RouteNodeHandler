#include "../include/TrafficManager.h"
#include "../include/Entity.h" // Include the base Entity class
#include <iostream>

// Add a generic Entity to the manager
void TrafficManager::addEntity(std::shared_ptr<Entity> entity)
{
    entities.push_back(entity); // Store any Entity (NPC, Vehicle, etc.)
}

// Update all entities
void TrafficManager::updateEntities()
{
    for (auto &entity : entities)
    {
        entity->move(); // Call move() on every entity (NPC or Vehicle)
    }
}
