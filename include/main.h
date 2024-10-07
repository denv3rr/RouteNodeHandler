#ifndef MAIN_H
#define MAIN_H

#include "functions.h"
#include "NodeManager.h"
#include "TrafficManager.h"
#include "PathfindingManager.h"
#include "NPC.h"
#include "Vehicle.h"
#include <vector>
#include <unistd.h>

// Function declarations for initializing NPCs and Vehicles
void initializeNPCs(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<NPC> &npcs, int numNPCs);
void initializeVehicles(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<Vehicle> &vehicles, int numVehicles);
void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager, PathfindingManager &pathfindingManager);

#endif // MAIN_H
