#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include "Node.h"
#include <vector>

class NodeManager
{
public:
    void addNode(float x, float y, float z);              // Add a new node
    void updateNodes();                                   // For any future node update logic
    void initializeNodes(NodeManager &nodeManager);       // Initialize the nodes (connected)
    Node *findNodeById(int id);                           // Find a node by ID (needed for pathfinding)
    std::vector<Node *> findPath(Node *start, Node *end); // Future pathfinding handled here

private:
    std::vector<Node> node;
};

#endif // NODE_MANAGER_H