#include "../include/NodeManager.h"
#include "../include/Node.h"
#include <iostream>
#include <cmath> // For std::sqrt
#include <queue> // For priority queue
#include <unordered_map>
#include <algorithm> // For std::reverse

NodeManager::NodeManager() {}

// Initialize nodes in a grid pattern with specified spacing
void NodeManager::createNodes(float spacing, int gridSize)
{
    int nodeID = 0;
    for (int x = 0; x < gridSize; ++x)
    {
        for (int y = 0; y < gridSize; ++y)
        {
            for (int z = 0; z < gridSize; ++z)
            {
                nodes.emplace_back(std::make_shared<Node>(nodeID++, x * spacing, y * spacing, z * spacing));
            }
        }
    }
}

// Print all nodes for debugging
void NodeManager::printNodes() const
{
    for (const auto &node : nodes)
    {
        std::cout << "Node ID: " << node->getId() << " at ("
                  << node->getX() << ", " << node->getY() << ", " << node->getZ() << ")\n";
    }
}

// Getter for nodes
std::vector<std::shared_ptr<Node>> &NodeManager::getNodes()
{
    return nodes;
}

// Heuristic cost estimate for pathfinding using std::shared_ptr<Node>
float NodeManager::heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
{
    return std::sqrt(std::pow(goal->getX() - start->getX(), 2) +
                     std::pow(goal->getY() - start->getY(), 2) +
                     std::pow(goal->getZ() - start->getZ(), 2));
}

// Distance function for pathfinding using std::shared_ptr<Node>
float NodeManager::distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
{
    return heuristicCostEstimate(start, goal); // Use shared_ptr instead of raw pointers
}

// Implement the A* pathfinding algorithm
std::vector<Node *> NodeManager::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    std::cout << "Initiating pathfinding algorithm..." << std::endl;

    // Initialize the open set
    std::priority_queue<std::pair<float, std::shared_ptr<Node>>,
                        std::vector<std::pair<float, std::shared_ptr<Node>>>,
                        std::greater<std::pair<float, std::shared_ptr<Node>>>>
        openSet;

    // Place start node in open set
    openSet.emplace(0.0f, startNode);

    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> cameFrom;
    std::unordered_map<std::shared_ptr<Node>, float> gScore;
    std::unordered_map<std::shared_ptr<Node>, float> fScore;

    gScore[startNode] = 0.0f;
    fScore[startNode] = heuristicCostEstimate(startNode, goalNode);

    // Main loop
    while (!openSet.empty())
    {
        std::shared_ptr<Node> current = openSet.top().second;
        openSet.pop();

        if (current == goalNode)
        {
            std::cout << "Goal node reached. Reconstructing path." << std::endl;
            return reconstructPath(cameFrom, current);
        }

        for (const auto &neighbor : current->getNeighbors())
        {
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

    std::cout << "No path found." << std::endl;
    return std::vector<Node *>(); // Return empty if no path found
}

// Reconstruct path function definition
std::vector<Node *> NodeManager::reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current)
{
    std::vector<Node *> path;
    while (cameFrom.find(current) != cameFrom.end())
    {
        path.push_back(current.get()); // Use raw pointer
        current = cameFrom[current];
    }
    path.push_back(current.get()); // Add the start node

    std::reverse(path.begin(), path.end());
    return path;
}
