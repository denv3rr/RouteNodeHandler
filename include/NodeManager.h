#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include "Node.h"

class NodeManager
{
public:
public:
    NodeManager();
    void initializeNodes(int gridSize, float spacing);
    std::vector<Node> getNodes() const;
    std::vector<Node *> findPath(Node *start, Node *goal); // A* Pathfinding

private:
    std::vector<Node> nodes;

    // Helper methods for A*
    float heuristicCostEstimate(const Node *start, const Node *goal) const;
    std::vector<Node *> getNeighbors(Node *node);
};

#endif // NODE_MANAGER_H
