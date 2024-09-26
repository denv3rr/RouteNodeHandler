/* *************************************************
 * Node.cpp
 * Purpose: create an instance of Node class, get its ID, add neighboring
 *          nodes, and finally, update neighbors (with getNeighbors()
 *          function).
 ************************************************* */

#include "../include/Node.h"
#include <iostream>
#include <cmath> // for distance calculations

// Node constructor
Node::Node(int id, float x, float y, float z) : id(id), x(x), y(y), z(z) {}

int Node::getId() const
{
    return id;
}

std::vector<Node> nodes;

void createNode(int id)
{
    float x = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10000.0)); // 10x10km area
    float y = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10000.0));
    float z = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 100.0)); // z for terrain elevation if needed
    nodes.push_back(Node(id, x, y, z));
}

void Node::addNeighbor(Node *neighbor)
{
    float distance = std::sqrt(std::pow((neighbor->getX() - this->getX()), 2) +
                               std::pow((neighbor->getY() - this->getY()), 2) +
                               std::pow((neighbor->getZ() - this->getZ()), 2));

    if (distance < 1000.0) // Add neighbors within a threshold distance
    {
        neighbors.push_back(neighbor);
    }
}

// Accessor functions
const std::vector<Node *> &Node::getNeighbors() const
{
    return neighbors;
}

float Node::getX() const
{
    return x;
}

float Node::getY() const
{
    return y;
}

float Node::getZ() const
{
    return z;
}

void initializeNodes(std::vector<Node> &nodes)
{
    /* Creates proximity-based connections between the current nodes
       by adding the next node as a neighbor. */
    std::cout << "Initializing nodes..." << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        for (size_t j = 0; j < nodes.size(); ++j)
        {
            if (i != j)
            {
                nodes[i].addNeighbor(&nodes[j]); // Add neighbors based on distance
            }
        }
    }
}