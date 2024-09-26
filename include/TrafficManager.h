/* *************************************************
 * TrafficManager.h
 * Purpose: TrafficManager header file for creation of
 *          TrafficManager class that handles created objects
 *          (such as NPCs, vehicles, or others) Node traffic.
 ************************************************* */
#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

#include "Node.h"
#include "NPC.h"
#include "Vehicle.h"
#include "NodeManager.h" // Include NodeManager for dynamic node creation
#include <iostream>
#include <vector>

class TrafficManager
{
public:
    std::vector<NPC *> npcs;
    std::vector<Vehicle *> vehicles;

    void addNPC(NPC *npc);
    void addVehicle(Vehicle *vehicle);

    // Set reference to NodeManager
    void setNodeManager(NodeManager *nodeManager);

    // Check if dynamic code creation is needed
    void updateTraffic();

private:
    NodeManager *nodeManager; // Pointer to NodeManager for creation of new nodes
};

#endif // TRAFFICMANAGER_H