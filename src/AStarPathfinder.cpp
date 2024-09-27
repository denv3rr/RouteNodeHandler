#include "AStarPathfinder.h"
#include <cmath>
#include <algorithm>
#include <iostream>

float AStarPathfinder::heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
{
    return std::sqrt(std::pow(goal->getX() - start->getX(), 2) +
                     std::pow(goal->getY() - start->getY(), 2) +
                     std::pow(goal->getZ() - start->getZ(), 2));
}

float AStarPathfinder::distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
{
    return heuristicCostEstimate(start, goal);
}

std::vector<Node *> AStarPathfinder::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    // Same A* logic as before
    std::priority_queue<std::pair<float, std::shared_ptr<Node>>,
                        std::vector<std::pair<float, std::shared_ptr<Node>>>,
                        std::greater<std::pair<float, std::shared_ptr<Node>>>>
        openSet;

    openSet.emplace(0.0f, startNode);
    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> cameFrom;
    std::unordered_map<std::shared_ptr<Node>, float> gScore;
    std::unordered_map<std::shared_ptr<Node>, float> fScore;

    gScore[startNode] = 0.0f;
    fScore[startNode] = heuristicCostEstimate(startNode, goalNode);

    while (!openSet.empty())
    {
        std::shared_ptr<Node> current = openSet.top().second;
        openSet.pop();

        if (current == goalNode)
        {
            return reconstructPath(cameFrom, current);
        }

        for (const auto &neighbor : current->getNeighbors())
        {
            if (!neighbor)
                continue;
            float tentative_gScore = gScore[current] + distance(current, neighbor);

            if (tentative_gScore < gScore[neighbor] || gScore.find(neighbor) == gScore.end())
            {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + heuristicCostEstimate(neighbor, goalNode);
                openSet.emplace(fScore[neighbor], neighbor);
            }
        }
    }
    return std::vector<Node *>();
}

std::vector<Node *> AStarPathfinder::reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current)
{
    std::vector<Node *> path;
    while (cameFrom.find(current) != cameFrom.end())
    {
        path.push_back(current.get());
        current = cameFrom[current];
    }
    path.push_back(current.get());
    std::reverse(path.begin(), path.end());
    return path;
}
