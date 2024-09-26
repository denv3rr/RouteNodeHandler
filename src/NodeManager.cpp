#include "../include/NodeManager.h"
#include <iostream>

// Constructor
NodeManager::NodeManager() {}

// Create a 3D grid of nodes
void NodeManager::initializeNodes(int gridSize, float spacing)
{
    nodes.clear();
    int nodeId = 1;

    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            for (int k = 0; k < gridSize; ++k)
            {
                nodes.emplace_back(nodeId++, i * spacing, j * spacing, k * spacing);
            }
        }
    }

    // Establish neighbors for each node in a grid structure
    for (Node &node : nodes)
    {
        for (Node &potentialNeighbor : nodes)
        {
            // Basic neighbor logic: nodes are neighbors if they are adjacent on any axis
            if (&node != &potentialNeighbor &&
                (std::abs(node.getX() - potentialNeighbor.getX()) <= spacing) &&
                (std::abs(node.getY() - potentialNeighbor.getY()) <= spacing) &&
                (std::abs(node.getZ() - potentialNeighbor.getZ()) <= spacing))
            {
                node.addNeighbor(&potentialNeighbor);
            }
        }
    }
}

// Return all nodes
const std::vector<Node> &NodeManager::getNodes() const
{
    return nodes;
}

// Print all nodes for debugging purposes
void NodeManager::printNodes() const
{
    for (const Node &node : nodes)
    {
        std::cout << "Node ID: " << node.getId()
                  << " at (" << node.getX() << ", " << node.getY() << ", " << node.getZ() << ")" << std::endl;
    }
}
