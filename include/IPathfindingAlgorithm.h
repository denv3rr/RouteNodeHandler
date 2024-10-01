#ifndef IPATHFINDINGALGORITHM_H
#define IPATHFINDINGALGORITHM_H

#include <memory>
#include <vector>
#include "Node.h"

class IPathfindingAlgorithm
{
public:
    virtual ~IPathfindingAlgorithm() = default;

    // Pure virtual method for finding a path
    virtual std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) = 0;
};

#endif // IPATHFINDINGALGORITHM_H
