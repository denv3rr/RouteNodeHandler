/* *************************************************
 * TrafficManager.cpp
 * Purpose: File for management of TrafficManager class
 *          that handles traffic for created objects
 *          such as: NPCs, vehicles, etc.
 ************************************************* */
#include "TrafficManager.h"
#include <iostream>

void TrafficManager::addNPC(NPC *npc)
{
    npcs.push_back(npc);
}

void TrafficManager::updateTraffic()
{
    for (auto &npc : npcs)
    {
        Node *currentNode = npc->getCurrentNode();
        const auto &neighbors = currentNode->getNeighbors();

        if (!neighbors.empty())
        {
            npc->moveToNode(neighbors[rand() % neighbors.size()]);
        }
    }
}