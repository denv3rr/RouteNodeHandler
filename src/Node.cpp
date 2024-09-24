/* *************************************************
 * Node.cpp
 * Purpose: create an instance of Node class, get its ID, add neighboring
 *          nodes, and finally, update neighbors (with getNeighbors()
 *          function).
 ************************************************* */

#include <iostream>
#include "../include/Node.h"

// Node class initializer
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

void initializeNodes(std::vector<Node> &nodes)
{
    /* Creates circular connection between the current nodes
       by adding the next node in the list. */
    std::cout << "Initializing nodes..." << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        nodes[i].addNeighbor(&nodes[(i + 1) % nodes.size()]);
    }
}