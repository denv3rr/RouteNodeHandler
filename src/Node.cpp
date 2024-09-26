/* *************************************************
 * Node.cpp
 * Purpose: create an instance of Node class, get its ID, add neighboring
 *          nodes, and finally, update neighbors (with getNeighbors()
 *          function).
 ************************************************* */

#include "../include/Node.h"
#include <iostream>

// Node class initializer
float x, y, z;
Node::Node(int id, float x, float y, float z) : id(id), x(x), y(y), z(z) {}

std::vector<Node> nodes;

void createNode(int id)
{
    float x = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10.0));
    float y = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10.0));
    float z = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10.0));
    nodes.push_back(Node(id, x, y, z));
}

void moveRandomly()
{
    x += (rand() % 3 - 1);
    y += (rand() % 3 - 1);
    z += (rand() % 3 - 1);
}

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
    /* Creates circular connection between the current nodes
       by adding the next node in the list. */
    std::cout << "Initializing nodes..." << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        nodes[i].addNeighbor(&nodes[(i + 1) % nodes.size()]);
    }
}