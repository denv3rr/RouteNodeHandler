#ifndef VEHICLE_H
#define VEHICLE_H

#include "Node.h"
#include <vector>

class Vehicle
{
public:
    Vehicle(int id, Node *startNode); // Constructor to initialize the vehicle
    void move();                      // Simulate movement
    int getId() const;                // Return Vehicle ID
    Node *getCurrentNode() const;     // Return current node

private:
    int id;                   // Vehicle identifier
    Node *currentNode;        // Current node the vehicle is at
    std::vector<Node *> path; // Path assigned to the vehicle
};

#endif // VEHICLE_H
