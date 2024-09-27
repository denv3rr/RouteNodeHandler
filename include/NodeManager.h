#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include "Node.h"
#include <vector>
#include <memory>
#include <unordered_map>

class NodeManager
{
public:
    NodeManager();
    void createNodes(float spacing, int gridSize);
    std::vector<std::shared_ptr<Node>> &getNodes();
    void printNodes() const;
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);

private:
    std::vector<std::shared_ptr<Node>> nodes;
    float heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    float distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;
    std::vector<Node *> reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current);

    // No need for 'NodeManager::' in header file
    int getIndex(int x, int y, int z, int gridSize); // Fix: Removed 'NodeManager::' here
};

#endif // NODEMANAGER_H
