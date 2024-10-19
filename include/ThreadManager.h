#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

#include "Node.h"
#include "TrafficManager.h"
#include "PathfindingManager.h"
#include "NPC.h"
#include "Vehicle.h"
#include <thread>
#include <mutex>
#include <vector>

void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode, int entityId, std::string entityType);
void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager, int npcCount, int vehicleCount);

#endif // THREAD_MANAGER_H