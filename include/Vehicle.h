#ifndef VEHICLE_H
#define VEHICLE_H

#include "Entity.h"
#include <vector>

class Vehicle : public Entity
{
private:
    std::vector<Node *> path; // The path for Vehicle to follow

public:
    Vehicle(int id, Node *startNode);

    void move() override; // Override the pure virtual function from Entity
};

#endif // VEHICLE_H
