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
    std::cout << "\033[32mInitializing node creation with gridSize: " << gridSize << "...\033[0m" << std::endl;

    // First pass: Create all nodes without neighbors
    for (int x = 0; x < gridSize; ++x)
    {
        for (int y = 0; y < gridSize; ++y)
        {
            for (int z = 0; z < gridSize; ++z)
            {
                std::cout << "Creating Node ID: \033[32m" << nodeID << " at (" << x << ", " << y << ", " << z << ")\033[0m" << std::endl;
                auto node = std::make_shared<Node>(nodeID++, x * spacing, y * spacing, z * spacing);
                nodes.push_back(node);
            }
        }
    }

    // Second pass: Assign neighbors to the nodes
    for (int x = 0; x < gridSize; ++x)
    {
        for (int y = 0; y < gridSize; ++y)
        {
            for (int z = 0; z < gridSize; ++z)
            {
                auto node = nodes[getIndex(x, y, z, gridSize)];

                // Add neighbors in -x, +x, -y, +y, -z, +z directions
                if (x > 0)
                {
                    int neighborIndex = getIndex(x - 1, y, z, gridSize);
                    std::cout << "Adding \033[32m-x\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m" << std::endl;
                    node->addNeighbor(nodes[neighborIndex]);
                }
                if (x < gridSize - 1)
                {
                    int neighborIndex = getIndex(x + 1, y, z, gridSize);
                    std::cout << "Adding \033[32m+x\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m" << std::endl;
                    node->addNeighbor(nodes[neighborIndex]);
                }

                if (y > 0)
                {
                    int neighborIndex = getIndex(x, y - 1, z, gridSize);
                    std::cout << "Adding \033[32m-y\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m" << std::endl;
                    node->addNeighbor(nodes[neighborIndex]);
                }
                if (y < gridSize - 1)
                {
                    int neighborIndex = getIndex(x, y + 1, z, gridSize);
                    std::cout << "Adding \033[32m+y\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m" << std::endl;
                    node->addNeighbor(nodes[neighborIndex]);
                }

                if (z > 0)
                {
                    int neighborIndex = getIndex(x, y, z - 1, gridSize);
                    std::cout << "Adding \033[32m-z\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m" << std::endl;
                    node->addNeighbor(nodes[neighborIndex]);
                }
                if (z < gridSize - 1)
                {
                    int neighborIndex = getIndex(x, y, z + 1, gridSize);
                    std::cout << "Adding \033[32m+z\033[0m neighbor to Node \033[32m" << node->getId() << "\033[0m, Neighbor Index: \033[32m" << neighborIndex << "\033[0m" << std::endl;
                    node->addNeighbor(nodes[neighborIndex]);
                }
            }
        }
    }

    std::cout << "\033[32mFinished creating all nodes and neighbors.\033[0m" << std::endl;
}

int NodeManager::getIndex(int x, int y, int z, int gridSize)
{
    return x * gridSize * gridSize + y * gridSize + z;
}

// Print all nodes for debugging
void NodeManager::printNodes() const
{
    for (const auto &node : nodes)
    {
        std::cout << "Node ID: \033[32m" << node->getId() << "\033[0m at \033[32m("
                  << node->getX() << ", " << node->getY() << ", " << node->getZ() << ")\033[0m\n";
        std::cout << "  Neighbors: ";
        for (const auto &neighbor : node->getNeighbors())
        {
            std::cout << neighbor->getId() << " ";
        }
        std::cout << std::endl;
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

// Find path function using std::shared_ptr<Node>
std::vector<Node *> NodeManager::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    std::cout << "Initiating pathfinding algorithm..." << std::endl;

    // Initialize the open set (priority queue) using fScore
    std::priority_queue<std::pair<float, std::shared_ptr<Node>>,
                        std::vector<std::pair<float, std::shared_ptr<Node>>>,
                        std::greater<std::pair<float, std::shared_ptr<Node>>>>
        openSet;

    // Place the start node in the open set with fScore 0
    openSet.emplace(0.0f, startNode);

    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> cameFrom;
    std::unordered_map<std::shared_ptr<Node>, float> gScore;
    std::unordered_map<std::shared_ptr<Node>, float> fScore;

    // Initialize the gScore and fScore for the start node
    gScore[startNode] = 0.0f;
    fScore[startNode] = heuristicCostEstimate(startNode, goalNode);

    // Main loop to process nodes in open set
    while (!openSet.empty())
    {
        // Get the node with the lowest fScore
        std::shared_ptr<Node> current = openSet.top().second;
        openSet.pop();

        // Debugging: show current node being processed
        std::cout << "Processing Node: " << current->getId() << std::endl;

        // Check if the current node is the goal
        if (current == goalNode)
        {
            std::cout << "\n\n\033[32mGoal node reached.\033[0m\n\nReconstructing path.\n\n"
                      << std::endl;
            return reconstructPath(cameFrom, current); // Return the constructed path
        }

        // Process each neighbor of the current node
        for (const auto &neighbor : current->getNeighbors())
        {
            // Ensure that neighbor is valid
            if (!neighbor)
            {
                std::cout << "Invalid neighbor for Node: " << current->getId() << std::endl;
                continue;
            }

            float tentative_gScore = gScore[current] + distance(current, neighbor);

            // If neighbor not in gScore or tentative_gScore is better
            if (gScore.find(neighbor) == gScore.end() || tentative_gScore < gScore[neighbor])
            {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + heuristicCostEstimate(neighbor, goalNode);

                // Debugging: log fScore for neighbor
                std::cout << "Neighbor: " << neighbor->getId() << " added to open set with fScore: " << fScore[neighbor] << std::endl;

                // Add the neighbor to the open set with its fScore
                openSet.emplace(fScore[neighbor], neighbor);
            }
            else
            {
                std::cout << "Neighbor: " << neighbor->getId() << " not added, worse gScore." << std::endl;
            }
        }
    }

    // If no path is found, return an empty vector
    std::cout << "\033[31mNo path found.\033[0m\n"
              << std::endl;
    return std::vector<Node *>(); // No path found
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
