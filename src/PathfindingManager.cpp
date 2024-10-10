#include "../include/PathfindingManager.h"
#include "../include/Node.h"
#include <iostream>

// Check if the node is blocked or unavailable
bool PathfindingManager::isNodeBlocked(const std::shared_ptr<Node> &node) const
{
    return node->isBlocked(); // Assuming Node has an isBlocked() method
}

std::vector<Node *> PathfindingManager::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    if (!pathfindingAlgorithm)
    {
        throw std::runtime_error("Pathfinding algorithm not set.");
    }

    // Check if start or goal nodes are blocked before beginning pathfinding
    if (isNodeBlocked(startNode) || isNodeBlocked(goalNode))
    {
        std::cout << "\033[31mStart or goal node is blocked. Cannot find path.\033[0m\n";
        return {};
    }

    // Use the selected algorithm to find the path
    auto path = pathfindingAlgorithm->findPath(startNode, goalNode);

    // Filter out blocked nodes during path traversal
    std::vector<Node *> filteredPath;
    for (auto &node : path)
    {
        if (isNodeBlocked(std::make_shared<Node>(*node)))
        {
            std::cout << "\033[31mBlocked node encountered: \033[0m" << node->getId() << "\033[31m. Skipping...\033[0m\n";
        }
        else
        {
            filteredPath.push_back(node);
        }
    }
    return filteredPath;
}