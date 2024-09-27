#include "../include/Vehicle.h"
#include <iostream>

// Constructor to initialize Vehicle with ID and starting node
Vehicle::Vehicle(int id, Node *startNode) : Entity(id, startNode) {}

// Move to the next node in the path (if path exists)
void Vehicle::move()
{
    if (!path.empty())
    {
        currentNode = path.front(); // Move to the next node
        path.erase(path.begin());   // Remove the first node from path
        std::cout << "Vehicle " << id << " moved to Node ID: " << currentNode->getId()
                  << " at (" << currentNode->getX() << ", " << currentNode->getY() << ", " << currentNode->getZ() << ")" << std::endl;
    }
}
