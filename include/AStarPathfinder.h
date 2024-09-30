#pragma once
#include "PathfindingManager.h"
#include "Node.h"
#include <unordered_map>
#include <vector>
#include <memory>

class AStarPathfinder : public PathfindingManager
{
public:
    // Find path implementation for A* algorithm
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) override;

private:
    float heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    float distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    std::vector<Node *> reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current);
};
