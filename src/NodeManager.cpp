#include "NodeManager.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <random> // For random number generation

// Adds a new node to the map and links it to nearby nodes
Node *NodeManager::addNode(float x, float y, float z)
{
    nodes.emplace_back(nodes.size() + 1, x, y, z);
    return &nodes.back();
}

// Adds a node dynamically during simulation and links to neighbors
Node *NodeManager::addDynamicNode(float x, float y, float z)
{
    std::cout << "Adding dynamic node at (" << x << ", " << y << ", " << z << ")\n";

    // Create new node
    Node *newNode = addNode(x, y, z);

    // Find nearby nodes to connect
    std::vector<Node *> nearbyNodes = findNearbyNodes(newNode, 5.0f); // Adjust distance as needed

    // Add bidirectional neighbors
    for (Node *neighbor : nearbyNodes)
    {
        newNode->addNeighbor(neighbor);
        neighbor->addNeighbor(newNode);
    }

    return newNode;
}

// Returns nodes within a certain distance from the new node
std::vector<Node *> NodeManager::findNearbyNodes(Node *newNode, float distance)
{
    std::vector<Node *> nearbyNodes;
    for (Node &node : nodes)
    {
        if (&node != newNode && distanceBetween(&node, newNode) <= distance)
        {
            nearbyNodes.push_back(&node);
        }
    }
    return nearbyNodes;
}

// Calculates the Euclidean distance between two nodes
float NodeManager::distanceBetween(Node *a, Node *b)
{
    return std::sqrt(std::pow(a->getX() - b->getX(), 2) +
                     std::pow(a->getY() - b->getY(), 2) +
                     std::pow(a->getZ() - b->getZ(), 2));
}

// Pathfinding function using A* algorithm
std::vector<Node *> NodeManager::findPath(Node *startNode, Node *goalNode)
{
    std::cout << "Finding path from Node " << startNode->getId() << " to Node " << goalNode->getId() << "\n";
    // A* pathfinding implementation from earlier

    std::priority_queue<std::pair<float, Node *>, std::vector<std::pair<float, Node *>>, std::greater<std::pair<float, Node *>>> openSet;
    std::unordered_map<Node *, Node *> cameFrom;
    std::unordered_map<Node *, float> gScore;
    std::unordered_map<Node *, float> fScore;

    for (Node &node : nodes)
    {
        gScore[&node] = std::numeric_limits<float>::infinity();
        fScore[&node] = std::numeric_limits<float>::infinity();
    }

    gScore[startNode] = 0;
    fScore[startNode] = distanceBetween(startNode, goalNode);

    openSet.push({fScore[startNode], startNode});

    while (!openSet.empty())
    {
        Node *currentNode = openSet.top().second;
        openSet.pop();

        if (currentNode == goalNode)
        {
            std::vector<Node *> path;
            while (currentNode != startNode)
            {
                path.push_back(currentNode);
                currentNode = cameFrom[currentNode];
            }
            path.push_back(startNode);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (Node *neighbor : currentNode->getNeighbors())
        {
            float tentativeGScore = gScore[currentNode] + distanceBetween(currentNode, neighbor);
            if (tentativeGScore < gScore[neighbor])
            {
                cameFrom[neighbor] = currentNode;
                gScore[neighbor] = tentativeGScore;
                fScore[neighbor] = gScore[neighbor] + distanceBetween(neighbor, goalNode);

                openSet.push({fScore[neighbor], neighbor});
            }
        }
    }

    return {}; // Return empty if no path is found
}
