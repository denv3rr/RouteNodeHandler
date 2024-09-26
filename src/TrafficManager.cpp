/* *************************************************
 * TrafficManager.cpp
 * Purpose: File for management of TrafficManager class
 *          that handles traffic for created objects
 *          such as: NPCs, vehicles, etc.
 ************************************************* */
#include "TrafficManager.h"
#include "../include/Node.h"
#include <iostream>

void TrafficManager::addNPC(NPC *npc)
{
    npcs.push_back(npc);
}

void TrafficManager::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

void TrafficManager::updateTraffic()
{
    for (auto &npc : npcs)
    {
        Node *currentNode = npc->getCurrentNode();
        const auto &neighbors = currentNode->getNeighbors();

        if (!neighbors.empty())
        {
            // move to a random neighbor within neighbors vector
            // "%" makes sure the random index is within the vector
            Node *nextNode = neighbors[rand() % neighbors.size()];
            npc->moveToNode(nextNode);
            std::cout << "NPC moved to Node ID: " << nextNode->getId();
            std::cout << " at (" << nextNode->getX() << ", " << nextNode->getY() << ", " << nextNode->getZ() << ")\n";
        }
    }

    for (auto &vehicle : vehicles)
    {
        Node *currentNode = vehicle->getCurrentNode();
        const auto &neighbors = currentNode->getNeighbors();

        if (!neighbors.empty())
        {
            // move to a random neighbor within neighbors vector
            // "%" makes sure the random index is within the vector
            Node *nextNode = neighbors[rand() % neighbors.size()];
            vehicle->moveToNode(nextNode);
            std::cout << "Vehicle moved to Node ID: " << nextNode->getId();
            std::cout << " at (" << nextNode->getX() << ", " << nextNode->getY() << ", " << nextNode->getZ() << ")\n";
        }
    }
}