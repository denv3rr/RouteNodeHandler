#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(int id, std::shared_ptr<Node> startNode) : Entity(id, startNode) {}

// Implement virtual destructor
Vehicle::~Vehicle() {}

// Override move function
void Vehicle::move()
{
    if (!path.empty())
    {
        currentNode = std::shared_ptr<Node>(path.front()); // Move to the next node
        path.erase(path.begin());                          // Remove the first node from path
        std::cout << "Vehicle " << id << " moved to Node ID: " << currentNode->getId() << "\n";
    }
}

// Override setPath function
void Vehicle::setPath(std::vector<Node *> newPath)
{
    path = newPath;
}
