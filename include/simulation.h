#ifndef SIMULATION_H
#define SIMULATION_H

#include "TrafficManager.h"
#include "NodeManager.h"
#include "NPC.h"
#include "Vehicle.h"
#include <vector>

void initializeNPCs(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<NPC> &npcs, int npcCount);
void initializeVehicles(TrafficManager &trafficManager, const std::vector<std::shared_ptr<Node>> &nodes, std::vector<Vehicle> &vehicles, int vehicleCount);
void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles);

#endif // SIMULATION_H
