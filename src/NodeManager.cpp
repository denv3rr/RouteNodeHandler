#include "NodeManager.h"
#include <queue>
#include <unordered_map>
#include <cmath>

struct NodeWithCost
{
    Node *node;
    float cost;
    bool operator<(const NodeWithCost &other) const
    {
        return cost > other.cost;
    }
};

std::vector<Node *> findPath(Node *startNode, Node *goalNode)
{
    std::priority_queue<NodeWithCost> openSet;
    std::unordered_map<Node *, Node *> cameFrom;
    std::unordered_map<Node *, float> gScore;

    openSet.push({startNode, 0.0f});
    gScore[startNode] = 0.0f;
}
