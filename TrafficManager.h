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

class TrafficManager
{
public:
    void addNPC(NPC *npc);
    void updateTraffic();

private:
    std::vector<NPC *> npcs; // creates NPC vector
};

#endif // TRAFFICMANAGER_H