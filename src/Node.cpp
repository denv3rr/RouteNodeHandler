#include "../include/Node.h"

// Constructor
Node::Node(int nodeId, int xCoord, int yCoord, int zCoord) : id(nodeId), x(xCoord), y(yCoord), z(zCoord) {}

// Getters
int Node::getId() const
{
    return id;
}

int Node::getX() const
{
    return x;
}

int Node::getY() const
{
    return y;
}

int Node::getZ() const
{
    return z;
}

// Setters
void Node::setId(int newId)
{
    id = newId;
}

void Node::setX(int newX)
{
    x = newX;
}

void Node::setY(int newY)
{
    y = newY;
}

void Node::setZ(int newZ)
{
    z = newZ;
}

// Neighbor handling
void Node::addNeighbor(std::shared_ptr<Node> neighbor)
{
    neighbors.push_back(neighbor);
}

std::vector<std::shared_ptr<Node>> Node::getNeighbors() const
{
    return neighbors;
}
