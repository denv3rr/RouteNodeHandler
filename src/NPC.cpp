#include "../include/NPC.h"
#include <iostream>

// Constructor to initialize NPC with an ID and starting node
NPC::NPC(int id, Node *startNode) : id(id), currentNode(startNode) {}

// Return NPC ID
int NPC::getId() const
{
    return id;
}

// Return the current node the NPC is at
Node *NPC::getCurrentNode() const
{
    return currentNode;
}

// Move to the next node in the path (if path exists)
void NPC::move()
{
    if (!path.empty())
    {
        currentNode = path.front(); // Move to the next node
        path.erase(path.begin());   // Remove the first node from path
        std::cout << "NPC " << id << " moved to Node ID: " << currentNode->getId()
                  << " at (" << currentNode->getX() << ", " << currentNode->getY() << ", " << currentNode->getZ() << ")" << std::endl;
    }
}
