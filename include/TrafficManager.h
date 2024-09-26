#ifndef TRAFFIC_MANAGER_H
#define TRAFFIC_MANAGER_H

#include "Node.h"
#include <vector>
#include <unordered_map>

class NPC;
class Vehicle;

class TrafficManager
{
public:
    void addNPC(NPC *npc);             // Add an NPC to manage
    void addVehicle(Vehicle *vehicle); // Add a vehicle to manage
    void updateEntities();             // Update positions of all entities

private:
    std::vector<NPC *> npcs;         // Managed NPCs
    std::vector<Vehicle *> vehicles; // Managed Vehicles
};

#endif // TRAFFIC_MANAGER_H
