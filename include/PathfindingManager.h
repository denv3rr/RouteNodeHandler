#ifndef PATHFINDINGMANAGER_H
#define PATHFINDINGMANAGER_H

#include <memory>
#include <stdexcept>
#include "IPathfindingAlgorithm.h"
#include "NodeManager.h"

class PathfindingManager
{
private:
    std::shared_ptr<IPathfindingAlgorithm> pathfindingAlgorithm;
    NodeManager &nodeManager;

public:
    // Constructor to initialize with NodeManager
    PathfindingManager(NodeManager &nodeMgr) : nodeManager(nodeMgr) {}

    // Set the pathfinding algorithm at runtime
    void setAlgorithm(std::shared_ptr<IPathfindingAlgorithm> algorithm)
    {
        pathfindingAlgorithm = algorithm;
    }

    // Check if an algorithm is set
    bool hasAlgorithm() const
    {
        return pathfindingAlgorithm != nullptr;
    }

    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);

    bool isNodeBlocked(const std::shared_ptr<Node> &) const;
};

#endif // PATHFINDINGMANAGER_H
