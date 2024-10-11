#include "../include/PathfindingManager.h"
#include "../include/Node.h"
#include <iostream>

// Check if the node is blocked or unavailable
bool PathfindingManager::isNodeBlocked(const std::shared_ptr<Node> &node) const
{
    return node->isBlocked(); // Assuming Node has an isBlocked() method
}

std::vector<Node *> PathfindingManager::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode, const std::string &entityType, int entityId)
{
    if (!pathfindingAlgorithm)
    {
        throw std::runtime_error("Pathfinding algorithm not set.");
    }

    // Output entity details
    std::cout << "Entity: " << entityType << " " << entityId << " - Start Node: " << startNode->getId()
              << " Goal Node: " << goalNode->getId() << "\n";

    // If start or goal is blocked, try finding subnodes
    if (isNodeBlocked(startNode))
    {
        std::cout << "Entity: " << entityType << " " << entityId << " - Start node blocked, trying subnodes...\n";
        auto subnodes = nodeManager.createSubnodes(startNode);
        if (!subnodes.empty())
        {
            startNode = subnodes[0]; // Pick the first subnode as the new start point
        }
    }

    if (isNodeBlocked(goalNode))
    {
        std::cout << "Entity: " << entityType << " " << entityId << " - Goal node blocked, trying subnodes...\n";
        auto subnodes = nodeManager.createSubnodes(goalNode);
        if (!subnodes.empty())
        {
            goalNode = subnodes[0]; // Pick the first subnode as the new goal
        }
    }

    // Use the selected algorithm to find the path
    auto path = pathfindingAlgorithm->findPath(startNode, goalNode);

    // Log the pathfinding result
    if (path.empty())
    {
        std::cout << "Entity: " << entityType << " " << entityId << " - No path found.\n";
    }
    else
    {
        std::cout << "Entity: " << entityType << " " << entityId << " - Path found.\n";
    }

    return path;
}
