#include "AStarPathfinder.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits> // For infinity

std::vector<Node *> AStarPathfinder::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    std::cout << "\033[32mInitiating pathfinding algorithm...\033[0m\n";
    std::cout << "\033[32mStart Node: \033[0m" << startNode->getId() << " at (" << startNode->getX() << ", " << startNode->getY() << ", " << startNode->getZ() << ")\n";
    std::cout << "\033[32mGoal Node: \033[0m" << goalNode->getId() << " at (" << goalNode->getX() << ", " << goalNode->getY() << ", " << goalNode->getZ() << ")\n";

    // Priority queue setup for A*
    std::priority_queue<
        std::pair<float, std::shared_ptr<Node>>,
        std::vector<std::pair<float, std::shared_ptr<Node>>>,
        std::greater<std::pair<float, std::shared_ptr<Node>>>>
        openSet;

    openSet.emplace(0.0f, startNode);

    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> cameFrom;
    std::unordered_map<std::shared_ptr<Node>, float> gScore;
    std::unordered_map<std::shared_ptr<Node>, float> fScore;

    // Initialize gScore for all nodes as "infinity"
    gScore[startNode] = 0.0f;
    fScore[startNode] = heuristicCostEstimate(startNode, goalNode);

    // Set all other gScores to infinity (they haven't been visited yet)
    for (const auto &node : startNode->getNeighbors())
    {
        gScore[node] = std::numeric_limits<float>::infinity();
    }

    while (!openSet.empty())
    {
        std::shared_ptr<Node> current = openSet.top().second;
        openSet.pop();

        std::cout << "\033[37mProcessing Node: \033[0m" << current->getId() << std::endl;

        if (current == goalNode)
        {
            std::cout << "\n\n\033[32mGoal node reached.\033[0m\n\nReconstructing path...\n\n";
            return reconstructPath(cameFrom, current);
        }

        for (const auto &neighbor : current->getNeighbors())
        {
            if (!neighbor)
            {
                std::cout << "\033[31mInvalid neighbor for Node: \033[0m" << current->getId() << std::endl;
                continue;
            }

            float tentative_gScore = gScore[current] + distance(current, neighbor);

            std::cout << "\033[33mEvaluating Neighbor: \033[0m" << neighbor->getId() << "\n"
                      << "Current gScore: " << gScore[neighbor] << ", Tentative gScore: " << tentative_gScore << "\n";

            // If this path to the neighbor is better or the neighbor hasn't been visited
            if (tentative_gScore < gScore[neighbor])
            {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + heuristicCostEstimate(neighbor, goalNode);

                std::cout << "\033[32mNeighbor: \033[0m" << neighbor->getId() << " with gScore: " << gScore[neighbor] << " added to open set.\n";
                openSet.emplace(fScore[neighbor], neighbor);
            }
            else
            {
                std::cout << "\033[31mNeighbor: \033[0m" << neighbor->getId() << " not added, worse gScore.\n";
            }
        }
    }

    std::cout << "\n\033[31mNo path found.\033[0m\n";
    return std::vector<Node *>();
}

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
