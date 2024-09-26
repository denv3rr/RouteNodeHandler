#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include "Node.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

// NodeManager class for managing a collection of nodes and pathfinding.
class NodeManager
{
public:
    // Adds a new node to the map
    Node *addNode(float x, float y, float z = 0.0f);

    // Adds a dynamic node during simulation
    Node *addDynamicNode(float x, float y, float z = 0.0f);

    // Finds nodes near a given position
    std::vector<Node *> findNearbyNodes(Node *newNode, float distance);

    // Calculates the distance between two nodes
    float distanceBetween(Node *a, Node *b);

    // Finds a path using A* algorithm between two nodes
    std::vector<Node *> findPath(Node *startNode, Node *goalNode);

private:
    std::vector<Node> nodes; // List of all nodes
};

#endif // NODE_MANAGER_H
