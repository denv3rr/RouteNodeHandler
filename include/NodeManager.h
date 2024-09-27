#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include "Node.h"
#include "Pathfinder.h"
#include <vector>
#include <memory>

class NodeManager
{
public:
    NodeManager();
    void createNodes(float spacing, int gridSize);
    std::vector<std::shared_ptr<Node>> &getNodes();
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode);

private:
    std::vector<std::shared_ptr<Node>> nodes;
    std::unique_ptr<Pathfinder> pathfinder; // Use a unique pointer to any Pathfinder
};

#endif // NODEMANAGER_H
