#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include "Node.h"
#include <vector>

class NodeManager
{
public:
    NodeManager();
    void initializeNodes(int gridSize, float spacing); // Create a 3D grid of nodes
    const std::vector<Node> &getNodes() const;         // Retrieve all nodes
    void printNodes() const;                           // Optional: Print all nodes for debugging

private:
    std::vector<Node> nodes; // Store all nodes
};

#endif // NODE_MANAGER_H
