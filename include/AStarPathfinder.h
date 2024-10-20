#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H

#include "IPathfindingAlgorithm.h"
#include "Node.h"
#include <unordered_map>
#include <memory>
#include <vector>
#include <mutex>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>

class AStarPathfinder : public IPathfindingAlgorithm
{
public:
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) override;

private:
    float heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    float distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    std::vector<Node *> reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current);
};

#endif // ASTARPATHFINDER_H
