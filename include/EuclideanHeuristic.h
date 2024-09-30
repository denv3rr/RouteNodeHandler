#pragma once
#include "Heuristic.h"
#include <cmath>

class EuclideanHeuristic : public Heuristic
{
public:
    float calculate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const override
    {
        return std::sqrt(std::pow(goal->getX() - start->getX(), 2) +
                         std::pow(goal->getY() - start->getY(), 2) +
                         std::pow(goal->getZ() - start->getZ(), 2));
    }
};
