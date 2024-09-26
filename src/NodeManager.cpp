#include "../include/NodeManager.h"
#include <cmath> // For std::sqrt
#include <queue> // For priority queue
#include <unordered_map>
#include <algorithm> // For std::reverse
#include <iostream>

// Constructor
NodeManager::NodeManager() {}

// Create a 3D grid of nodes
void NodeManager::initializeNodes(int gridSize, float spacing)
{
    nodes.clear();
    int nodeId = 1;

    // Create a 3D grid of nodes
    for (int x = 0; x < gridSize; ++x)
    {
        for (int y = 0; y < gridSize; ++y)
        {
            for (int z = 0; z < gridSize; ++z)
            {
                Node newNode;
                newNode.nodeID = nodeID++;
                newNode.x = x * spacing;
                newNode.y = y * spacing;
                newNode.z = z * spacing;

                nodes.push_back(newNode);
            }
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
