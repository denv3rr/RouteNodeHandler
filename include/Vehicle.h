/* *************************************************
 * Vehicle.h
 * Purpose: Vehicle header file for creation of Vehicle class.
 ************************************************* */
#ifndef VEHICLE_H
#define VEHICLE_H

// Standard
#include <vector>

// Local
#include "Node.h"
#include "TrafficManager.h"

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

void initializeVehicles(TrafficManager &trafficManager, std::vector<Node> &nodes, std::vector<Vehicle> &vehicles);

#endif // VEHICLE_H