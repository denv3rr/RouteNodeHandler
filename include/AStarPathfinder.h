#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H

#include <vector>
#include <unordered_map>
#include <memory>
#include "Node.h"

class AStarPathfinder
{
public:
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);
    std::vector<Node *> reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current);

private:
    float heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    float distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
};

#endif
