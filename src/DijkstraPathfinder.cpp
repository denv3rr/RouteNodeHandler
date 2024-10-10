#include "../include/DijkstraPathfinder.h"
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <limits>

std::vector<Node *> DijkstraPathfinder::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    std::cout << "Using Dijkstra's algorithm...\n";

    std::priority_queue<
        std::pair<float, std::shared_ptr<Node>>,
        std::vector<std::pair<float, std::shared_ptr<Node>>>,
        std::greater<std::pair<float, std::shared_ptr<Node>>>>
        openSet;

    // Starting node within openSet vector
    openSet.emplace(0.0f, startNode);

    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> cameFrom;
    std::unordered_map<std::shared_ptr<Node>, float> gScore;

    gScore[startNode] = 0.0f;

    while (!openSet.empty())
    {
        std::shared_ptr<Node> current = openSet.top().second;
        openSet.pop();

        if (current == goalNode)
        {
            std::cout << "Goal node reached.\n";
            return reconstructPath(cameFrom, current);
        }

        for (const auto &neighbor : current->getNeighbors())
        {
            if (!neighbor)
                continue;

            float tentative_gScore = gScore[current] + distance(current, neighbor);
            if (gScore.find(neighbor) == gScore.end() || tentative_gScore < gScore[neighbor])
            {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                openSet.emplace(gScore[neighbor], neighbor);
            }
        }
    }

    std::cout << "No path found.\n";
    return std::vector<Node *>();
}

float DijkstraPathfinder::distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
{
    return std::sqrt(std::pow(goal->getX() - start->getX(), 2) +
                     std::pow(goal->getY() - start->getY(), 2) +
                     std::pow(goal->getZ() - start->getZ(), 2));
}

std::vector<Node *> DijkstraPathfinder::reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current)
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
