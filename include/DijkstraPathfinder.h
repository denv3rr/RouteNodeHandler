#ifndef DIJKSTRTAPATHFINDER_H
#define DIJKSTRTAPATHFINDER_H

#include "IPathfindingAlgorithm.h"
#include <unordered_map>
#include <memory>
#include <vector>

class DijkstraPathfinder : public IPathfindingAlgorithm
{
public:
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) override;

private:
    float distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    std::vector<Node *> reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current);
};

#endif // DIJKSTRTAPATHFINDER_H