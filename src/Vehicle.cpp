/* *************************************************
 * Vehicle.cpp
 * Purpose: creates an instance of Vehicle class.
 ************************************************* */
#ifndef VEHICLE_H
#define VEHICLE_H

#include "include/Node.h"

class Vehicle
{
public:
    Vehicle(int id, Node *startNode);
    int getId() const;
    Node *getCurrentNode() const;
    void moveToNode(Node *node);

private:
    int id;
    Node *currentNode;
};

#endif // VEHICLE_H