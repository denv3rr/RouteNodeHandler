#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include "Node.h"
#include <vector>
#include <unordered_map>
#include <memory> // For std::shared_ptr

class NodeManager
{
public:
    NodeManager();
    void createNodes(float spacing, int gridSize);
    std::vector<std::shared_ptr<Node>> &getNodes(); // Changed to shared_ptr
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);
    float heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const; // Updated to shared_ptr
    float distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const;              // Updated to shared_ptr

    // Function to print all nodes if needed
    void printNodes() const;

private:
    std::vector<std::shared_ptr<Node>> nodes;                                                                                                       // Changed to shared_ptr
    std::vector<Node *> reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current); // Updated to shared_ptr
};

#endif // NODEMANAGER_H
