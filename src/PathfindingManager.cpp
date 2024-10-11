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

    // If start or goal is blocked, try finding subnodes
    if (isNodeBlocked(startNode))
    {
        std::cout << "Start node blocked, trying subnodes...\n";
        auto subnodes = nodeManager.createSubnodes(startNode);
        if (!subnodes.empty())
        {
            startNode = subnodes[0]; // Pick the first subnode as the new start point
        }
    }

    if (isNodeBlocked(goalNode))
    {
        std::cout << "Goal node blocked, trying subnodes...\n";
        auto subnodes = nodeManager.createSubnodes(goalNode);
        if (!subnodes.empty())
        {
            goalNode = subnodes[0]; // Pick the first subnode as the new goal
        }
    }

    // Use the selected algorithm to find the path
    return pathfindingAlgorithm->findPath(startNode, goalNode);
}
