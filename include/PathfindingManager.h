#ifndef PATHFINDINGMANAGER_H
#define PATHFINDINGMANAGER_H

#include <memory>
#include "IPathfindingAlgorithm.h"

class PathfindingManager
{
private:
    std::shared_ptr<IPathfindingAlgorithm> pathfindingAlgorithm;

public:
    // Set the pathfinding algorithm at runtime
    void setAlgorithm(std::shared_ptr<IPathfindingAlgorithm> algorithm)
    {
        pathfindingAlgorithm = algorithm;
    }

    // Call the selected algorithm's findPath method
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
    {
        if (!pathfindingAlgorithm)
        {
            throw std::runtime_error("Pathfinding algorithm not set.");
        }
        return pathfindingAlgorithm->findPath(startNode, goalNode);
    }
};

#endif // PATHFINDINGMANAGER_H
