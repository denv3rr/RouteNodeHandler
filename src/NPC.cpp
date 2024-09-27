#include "../include/NPC.h"
#include <iostream>

NPC::NPC(int id, Node *startNode) : Entity(id, startNode) {}

// Implement virtual destructor
NPC::~NPC() {}

// Override move function
void NPC::move()
{
    if (!path.empty())
    {
        currentNode = path.front(); // Move to the next node
        path.erase(path.begin());   // Remove the first node from path
        std::cout << "NPC " << id << " moved to Node ID: " << currentNode->getId() << std::endl;
    }
}

// Override setPath function
void NPC::setPath(std::vector<Node *> newPath)
{
    path = newPath;
}
