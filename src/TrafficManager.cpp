#include "../include/TrafficManager.h"
#include "../include/NPC.h"
#include "../include/Vehicle.h"

// Add NPC to the manager
void TrafficManager::addNPC(NPC *npc)
{
    npcs.push_back(npc);
}

// Add Vehicle to the manager
void TrafficManager::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

// Update all entities (simplified example)
void TrafficManager::updateEntities()
{
    for (NPC *npc : npcs)
    {
        npc->move();
    }

    for (Vehicle *vehicle : vehicles)
    {
        vehicle->move();
    }
}
