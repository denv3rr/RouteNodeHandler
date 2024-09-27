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

// Heuristic cost estimate for pathfinding using raw pointers
float NodeManager::heuristicCostEstimate(const Node *start, const Node *goal) const
{
    return std::sqrt(std::pow(goal->getX() - start->getX(), 2) +
                     std::pow(goal->getY() - start->getY(), 2) +
                     std::pow(goal->getZ() - start->getZ(), 2));
}

// Distance function for raw pointers
float NodeManager::distance(const Node *start, const Node *goal) const
{
    return heuristicCostEstimate(start, goal); // Assuming distance is the Euclidean distance here
}

// Implement the A* pathfinding algorithm
std::vector<Node *> NodeManager::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    std::cout << "Initiating pathfinding algorithm...\n";

    std::priority_queue<std::pair<float, std::shared_ptr<Node>>,
                        std::vector<std::pair<float, std::shared_ptr<Node>>>,
                        std::greater<std::pair<float, std::shared_ptr<Node>>>>
        openSet;

    // Place start node in open set
    openSet.emplace(0.0f, startNode);

    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> cameFrom;
    std::unordered_map<std::shared_ptr<Node>, float> gScore;
    std::unordered_map<std::shared_ptr<Node>, float> fScore;

    // Initialize the start node's gScore and fScore
    gScore[startNode] = 0.0f;
    fScore[startNode] = heuristicCostEstimate(startNode.get(), goalNode.get()); // Convert to raw pointers

    // The main pathfinding loop
    while (!openSet.empty())
    {
        std::cout << "\033[32mPathfinding!\033[0m";
        std::shared_ptr<Node> current = openSet.top().second;
        openSet.pop();

        // If we reach the goal node, reconstruct the path
        if (current == goalNode)
        {
            std::cout << "Goal node reached. Reconstructing path.";
            return reconstructPath(cameFrom, current);
        }

        // Process the neighbors of the current node
        for (const auto &neighbor : current->getNeighbors())
        {
            float tentative_gScore = gScore[current] + distance(current.get(), neighbor.get());

            if (tentative_gScore < gScore[neighbor] || gScore.find(neighbor) == gScore.end())
            {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + heuristicCostEstimate(neighbor.get(), goalNode.get());
                openSet.emplace(fScore[neighbor], neighbor);
            }
        }
    }

    // If no path is found, return an empty vector
    return std::vector<Node *>();
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
