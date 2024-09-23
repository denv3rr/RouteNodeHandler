/* *************************************************
 * Node.cpp
 * Purpose: create an instance of Node class, get its ID, add neighboring
 *          nodes, and finally, update neighbors (with getNeighbors()
 *          function).
 ************************************************* */
#include "Node.h"

// Node initializer
Node::Node(int id) : id(id) {}

int Node::getId() const
{
    return id;
}

void Node::addNeighbor(Node *neighbor)
{
    neighbors.push_back(neighbor);
}

const std::vector<Node *> &Node::getNeighbors() const
{
    return neighbors;
}