#ifndef VEHICLE_H
#define VEHICLE_H

#include "Entity.h"
#include <vector>

class Vehicle : public Entity
{
public:
    Vehicle(int id, Node *startNode);
    int getId() const;
    Node *getCurrentNode() const;

    // Add this method to allow setting a path
    void setPath(const std::vector<Node *> &newPath);

    void move() override;

private:
    std::vector<Node *> path; // Store the Vehicle's path
};

#endif // VEHICLE_H
