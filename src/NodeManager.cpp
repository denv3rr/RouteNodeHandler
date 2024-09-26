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

    while (!openSet.empty())
    {
        Node *currentNode = openSet.top().node;
        openSet.pop();

        if (currentNode == goalNode)
        {
            // Reconstruct the path
            std::vector<Node *> path;
            while (currentNode != startNode)
            {
                path.push_back(currentNode);
                currentNode = cameFrom[currentNode];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (Node *neighbor : currentNode->getNeighbors())
        {
            float tentativeGScore = gScore[currentNode] + distanceBetween(currentNode, neighbor);

            if (tentativeGScore < gScore[neighbor] || gScore.find(neighbor) == gScore.end())
            {
                cameFrom[neighbor] = currentNode;
                gScore[neighbor] = tentativeGScore;
                float fScore = tentativeGScore + distanceBetween(neighbor, goalNode);
                openSet.push({neighbor, fScore});
            }
        }
    }
    return {}; // No path found
}

float distanceBetween(Node *a, Node *b)
{
    return std::sqrt(std::pow(b->getX() - a->getX(), 2) +
                     std::pow(b->getY() - a->getY(), 2) +
                     std::pow(b->getZ() - a->getZ(), 2));
}
