#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include "Node.h"
#include "AStarPathfinder.h"    // Include logic for A*
#include "DijkstraPathfinder.h" // Including logic for Dijkstra
#include <memory>
#include <vector>

class NodeManager
{
private:
    std::vector<std::shared_ptr<Node>> nodes;
    std::map<int, std::vector<std::shared_ptr<Node>>> subnodes; // Map node ID to its subnodes
    std::unique_ptr<AStarPathfinder> pathfinder;                // Pathfinding logic

public:
    NodeManager();

    // Create nodes in a grid
    void createNodes(float spacing, int gridSize);

    // Create subnodes dynamically when required
    std::vector<std::shared_ptr<Node>> createSubnodes(const std::shared_ptr<Node> &parentNode);

    // Getter for nodes and subnodes
    std::vector<std::shared_ptr<Node>> &getNodes();
    std::vector<std::shared_ptr<Node>> getSubnodes(int parentNodeID);

    // Pathfinding function
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);

    // Function to print nodes and subnodes
    void printNodes() const;

    // Mark nodes as blocked/unblocked
    void setNodeBlocked(int nodeId, bool blocked);
    void randomlyBlockNodes();
};

#endif // NODEMANAGER_H
