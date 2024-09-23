/* *************************************************
 * Vehicle.cpp
 * Purpose: creates an instance of Vehicle class.
 ************************************************* */
#include "include/Vehicle.h"

void initializeVehicles(TrafficManager &trafficManager, std::vector<Node> &nodes, std::vector<Vehicle> &vehicles)
{
    std::cout << "Initializing Vehicles..." << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        vehicles.emplace_back(i + 1, &nodes[i]);
        trafficManager.addVehicle(&vehicles.back());
    }
}

// Vehicle class implementation + initializer list
Vehicle::Vehicle(int id, Node *startNode) : id(id), currentNode(startNode) {}

int Vehicle::getId() const
{
    return id;
}

Node *Vehicle::getCurrentNode() const
{
    return currentNode;
}

void Vehicle::moveToNode(Node *node)
{
    currentNode = node;
}