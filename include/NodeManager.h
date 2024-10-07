#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include "Node.h"
#include "AStarPathfinder.h" // Include pathfinding logic
#include <memory>
#include <vector>

class NodeManager
{
public:
    NodeManager();

    // Function to create nodes in a grid
    void createNodes(float spacing, int gridSize);

    // Getter for nodes
    std::vector<std::shared_ptr<Node>> &getNodes();

    // Function to find a path between two nodes
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);

    // Function to print all nodes for debugging
    void printNodes() const; // Add this declaration

    // Function to set a node to a status of "blocked" by ID
    void setNodeBlocked(int nodeId, bool blocked);

    void randomlyBlockNodes();

private:
    // Function to get the index of a node in the grid
    int getIndex(int x, int y, int z, int gridSize); // Add this declaration

    std::vector<std::shared_ptr<Node>> nodes;    // Store nodes
    std::unique_ptr<AStarPathfinder> pathfinder; // Pathfinding logic
};

#endif // NODEMANAGER_H
