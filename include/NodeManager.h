#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include "Node.h"
#include <iostream>
#include <vector>

class NodeManager
{
public:
    std::vector<Node> nodes;
    void addNode(float x, float y, float z);
    void updateNodes();
    void initializeNodes(NodeManager &nodeManager);

private:
};

#endif // NODE_MANAGER_H