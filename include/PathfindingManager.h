#pragma once
#include <vector>
#include <memory>

class Node; // Forward declaration

class PathfindingManager
{
public:
    virtual ~PathfindingManager() = default;

    // Pure virtual function to find a path
    virtual std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) = 0;
};
