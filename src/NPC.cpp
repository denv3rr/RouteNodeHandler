#include "../include/NPC.h"
#include <iostream>

// Constructor to initialize NPC with an ID and starting node
NPC::NPC(int id, Node *startNode) : Entity(id, startNode) {}

void NPC::setPath(const std::vector<Node *> &newPath)
{
    path = newPath; // Assign the new path to the NPC
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
