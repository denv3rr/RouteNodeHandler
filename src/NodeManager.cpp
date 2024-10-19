#include "NodeManager.h"
#include "Node.h"
#include "AStarPathfinder.h" // Include AStarPathfinder
#include <iostream>
#include <cmath> // For std::sqrt
#include <queue> // For priority queue
#include <unordered_map>
#include <algorithm> // For std::reverse

NodeManager::NodeManager() : pathfinder(std::make_unique<AStarPathfinder>()) {}

// Initialize nodes in a grid pattern with specified spacing
void NodeManager::createNodes(float spacing, int gridSize)
{
    int nodeID = 0;
    std::cout << "\033[32mInitializing node creation with gridSize: " << gridSize << "...\033[0m\n";

    // First pass: Create all nodes without neighbors
    for (int x = 0; x < gridSize; ++x)
    {
        for (int y = 0; y < gridSize; ++y)
        {
            for (int z = 0; z < gridSize; ++z)
            {
                std::cout << "Creating Node ID: \033[32m" << nodeID << " at (" << x << ", " << y << ", " << z << ")\033[0m\n";
                auto node = std::make_shared<Node>(nodeID++, x * spacing, y * spacing, z * spacing);
                nodes.push_back(node);
            }
        }
    }

    // Second pass: Assign neighbors to the nodes
    for (int x = 0; x < gridSize; ++x)
    {
        for (int y = 0; y < gridSize; ++y)
        {
            for (int z = 0; z < gridSize; ++z)
            {
                auto node = nodes[getIndex(x, y, z, gridSize)];

                // Add neighbors in -x, +x, -y, +y, -z, +z directions
                if (x > 0)
                {
                    int neighborIndex = getIndex(x - 1, y, z, gridSize);
                    // std::cout << "Adding \033[32m-x\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m\n";
                    node->addNeighbor(nodes[neighborIndex]);
                }
                if (x < gridSize - 1)
                {
                    int neighborIndex = getIndex(x + 1, y, z, gridSize);
                    // std::cout << "Adding \033[32m+x\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m\n";
                    node->addNeighbor(nodes[neighborIndex]);
                }

                if (y > 0)
                {
                    int neighborIndex = getIndex(x, y - 1, z, gridSize);
                    // std::cout << "Adding \033[32m-y\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m\n";
                    node->addNeighbor(nodes[neighborIndex]);
                }
                if (y < gridSize - 1)
                {
                    int neighborIndex = getIndex(x, y + 1, z, gridSize);
                    // std::cout << "Adding \033[32m+y\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m\n";
                    node->addNeighbor(nodes[neighborIndex]);
                }

                if (z > 0)
                {
                    int neighborIndex = getIndex(x, y, z - 1, gridSize);
                    // std::cout << "Adding \033[32m-z\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m\n";
                    node->addNeighbor(nodes[neighborIndex]);
                }
                if (z < gridSize - 1)
                {
                    int neighborIndex = getIndex(x, y, z + 1, gridSize);
                    // std::cout << "Adding \033[32m+z\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m\n";
                    node->addNeighbor(nodes[neighborIndex]);
                }
            }
        }
    }

    goalNode = nodes.back(); // Set goalNode to the last node in the grid
    std::cout << "\033[32mFinished creating all nodes and neighbors.\033[0m" << std::endl;
}

int NodeManager::getIndex(int x, int y, int z, int gridSize)
{
    return x * gridSize * gridSize + y * gridSize + z;
}

// Print all nodes for debugging
void NodeManager::printNodes() const
{
    for (const auto &node : nodes)
    {
        std::cout << "Node ID: \033[32m" << node->getId() << "\033[0m at \033[32m("
                  << node->getX() << ", " << node->getY() << ", " << node->getZ() << ")\033[0m\n";
        std::cout << "  Neighbors: ";
        for (const auto &neighbor : node->getNeighbors())
        {
            std::cout << neighbor->getId() << " ";
        }
        std::cout << std::endl;
    }
}

// Getter for nodes
std::vector<std::shared_ptr<Node>> &NodeManager::getNodes()
{
    return nodes;
}
std::shared_ptr<Node> NodeManager::getGoalNode()
{
    // Assuming goalNode is already set somewhere in your logic
    return goalNode; // Return the goal node, assuming it's a class member variable
}

// Find path function using A* pathfinding algorithm
std::vector<Node *> NodeManager::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    // Delegating the pathfinding to the Pathfinder object
    return pathfinder->findPath(startNode, goalNode);
}

// Set blocked nodes to a status of blocked
void NodeManager::setNodeBlocked(int nodeId, bool blockedStatus)
{
    if (nodeId >= 0 && nodeId < nodes.size())
    {
        nodes[nodeId]->setBlocked(blockedStatus);
        std::cout << "Node " << nodeId << " has been marked as " << (blockedStatus ? "blocked\n" : "available\n");
    }
}

void NodeManager::randomlyBlockNodes()
{
    for (auto &node : nodes)
    {
        if (rand() % 5 == 0) // Randomly block/unblock some nodes
        {
            bool blockStatus = rand() % 2 == 0; // Randomly block or unblock
            node->setBlocked(blockStatus);
            std::cout << "Node " << node->getId() << " has been " << (blockStatus ? "blocked\n" : "unblocked\n");
        }
    }
}

// Subnode grid creation (dynamic)
std::vector<std::shared_ptr<Node>> NodeManager::createSubnodes(const std::shared_ptr<Node> &parentNode)
{
    if (subnodes.find(parentNode->getId()) != subnodes.end())
    {
        return subnodes[parentNode->getId()]; // Return existing subnodes if already created
    }

    std::vector<std::shared_ptr<Node>> generatedSubnodes;
    float spacing = 0.5f; // Example smaller spacing for subnodes

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            for (int dz = -1; dz <= 1; ++dz)
            {
                if (dx == 0 && dy == 0 && dz == 0)
                    continue; // Skip the center (parent node itself)

                auto subnode = std::make_shared<Node>(
                    parentNode->getId() * 100 + (dx + 1) * 10 + (dy + 1) * 1 + dz,
                    parentNode->getX() + dx * spacing,
                    parentNode->getY() + dy * spacing,
                    parentNode->getZ() + dz * spacing);
                generatedSubnodes.push_back(subnode);
            }
        }
    }

    subnodes[parentNode->getId()] = generatedSubnodes;
    return generatedSubnodes;
}
