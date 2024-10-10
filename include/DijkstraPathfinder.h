#ifndef DIJKSTRTAPATHFINDER_H
#define DIJKSTRTAPATHFINDER_H

#include "IPathfindingAlgorithm.h"
#include <memory>
#include <vector>

class DijkstraPathfinder : public IPathfindingAlgorithm
{
public:
    std::vector<Node *> findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode) override;
};

#endif // DIJKSTRTAPATHFINDER_H