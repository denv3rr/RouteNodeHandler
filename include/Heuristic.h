#pragma once // avoiding traditional inclusion guards *test
#include "Node.h"
#include <memory>

class Heuristic
{
public:
    virtual ~Heuristic() = default;

    // Pure virtual function for calculating heuristic cost
    virtual float calculate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const = 0;
};
