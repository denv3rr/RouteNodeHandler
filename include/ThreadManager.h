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

void displayEntityStatus(const std::string &entityType, int entityId, bool success, const std::string &status);
void showProgressWithEntity(const std::string &entityType, int entityId, float progress); // Declare here
void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode, int entityId, std::string entityType);
void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager, int npcCount, int vehicleCount);

#endif // THREAD_MANAGER_H
