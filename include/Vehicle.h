#ifndef VEHICLE_H
#define VEHICLE_H

#include "Entity.h"
#include "Node.h"

class Vehicle : public Entity
{
public:
    Vehicle(int id, Node *startNode);
    ~Vehicle() override;                             // Override the destructor
    void move() override;                            // Override the move function
    void setPath(std::vector<Node *> path) override; // Override setPath
};

#endif // VEHICLE_H
