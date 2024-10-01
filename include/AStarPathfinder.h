#include "IPathfindingAlgorithm.h"
#include <cmath>
#include <algorithm>
#include <iostream>

class AStarPathfinder : public IPathfindingAlgorithm
{
public:
    float heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
    {
        return std::sqrt(std::pow(goal->getX() - start->getX(), 2) +
                         std::pow(goal->getY() - start->getY(), 2) +
                         std::pow(goal->getZ() - start->getZ(), 2));
    }

    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) override
    {
        // A* implementation here
    }
};
