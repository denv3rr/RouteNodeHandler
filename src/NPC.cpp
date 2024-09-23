/* *************************************************
 * NPC.cpp
 * Purpose: creates an instance of NPC class.
 ************************************************* */

// Standard
#include <iostream>

// Local
#include "NPC.h"
#include "TrafficManager.h"

NPC::NPC(int id, Node *startNode) : id(id), currentNode(startNode) {}

int NPC::getId() const
{
    return id;
}

Node *NPC::getCurrentNode() const
{
    return currentNode;
}

void NPC::moveToNode(Node *node)
{
    currentNode = node;
}

void initializeNPCs(TrafficManager &trafficManager, std::vector<Node> &nodes, std::vector<NPC> &npcs)
{
    std::cout << "Initializing NPCs..." << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        npcs.emplace_back(i + 1, &nodes[i]);
        trafficManager.addNPC(&npcs.back());
    }
}