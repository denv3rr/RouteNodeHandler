#include "../include/PathfindingManager.h"
#include "../include/Node.h"
#include <iostream>

std::vector<Node *> PathfindingManager::findPath(std::share_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    if (!pathfindingAlgorithm)
    {
        throw std::runtime_error("Pathfinding algorithm not set.");
    }

    std::cout << "Pathfinding initiated from Node " << startNode->getId()
              << " to Node " << goalNode->getId() << std::endl;

    // Iterate through neighbors of the startNode, and skip blocked nodes
    for (const auto &neighbor : startNode->getNeighbors())
    {
        if (neighbor->isBlocked())
        {
            std::cout << "Skipping blocked neighbor: " << neighbor->getId() << std::endl;
            continue;
        }
    }

    // Call selected pathfinding algorithm
    return pathfindingAlgorithm->findPath(startNode, goalNode);
}