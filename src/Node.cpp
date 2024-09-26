#include "../include/Node.h"
#include <iostream>

// Constructor
Node::Node(int id, float x, float y, float z) : id(id), x(x), y(y), z(z) {}

// Return Node ID
int Node::getId() const
{
    return id;
}

// Add a neighboring node to the vector
void Node::addNeighbor(Node *neighbor)
{
    neighbors.push_back(neighbor);
}

// Return neighbors
const std::vector<Node *> &Node::getNeighbors() const
{
    return neighbors;
}

// Return X coordinate
float Node::getX() const
{
    return x;
}

// Return Y coordinate
float Node::getY() const
{
    return y;
}

// Return Z coordinate
float Node::getZ() const
{
    return z;
}
