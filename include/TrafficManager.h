/* *************************************************
 * TrafficManager.h
 * Purpose: TrafficManager header file for creation of
 *          TrafficManager class that handles created objects
 *          (such as NPCs, vehicles, or others) Node traffic.
 ************************************************* */
#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

// Standard
#include <vector>

// Local
#include "NPC.h"
#include "Vehicle.h"

class TrafficManager
{
public:
    void addNPC(NPC *npc);
    void addVehicle(Vehicle *vehicle);
    void updateTraffic();

private:
    std::vector<NPC *> npcs;         // creates NPC vector
    std::vector<Vehicle *> vehicles; // creates Vehicles vector
};

#endif // TRAFFICMANAGER_H