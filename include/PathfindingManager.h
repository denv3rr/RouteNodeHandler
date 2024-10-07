#ifndef PATHFINDINGMANAGER_H
#define PATHFINDINGMANAGER_H

#include <memory>
#include <stdexcept>
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

    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);

    bool isNodeBlocked(const std::shared_ptr<Node> &) const;
};

#endif // PATHFINDINGMANAGER_H
