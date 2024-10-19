#ifndef INITIALIZATIONMANAGER_H
#define INITIALIZATIONMANAGER_H

#include "TrafficManager.h"
#include "Node.h"
#include "NPC.h"
#include "Vehicle.h"
#include <vector>

void initializeNPCs(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<NPC> &npcs, int numNPCs);
void initializeVehicles(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<Vehicle> &vehicles, int numVehicles);

#endif // INITIALIZATIONMANAGER_H