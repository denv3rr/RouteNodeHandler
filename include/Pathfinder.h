#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Node.h"
#include <vector>
#include <memory>

// Abstract base class for pathfinding
class Pathfinder {
public:
    virtual ~Pathfinder() = default;

    // Abstract method for finding a path
    virtual std::vector<Node*> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) = 0;
};

#endif // PATHFINDER_H
