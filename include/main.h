#ifndef MAIN_H
#define MAIN_H

#include "functions.h"
#include "NodeManager.h"
#include "TrafficManager.h"
#include "PathfindingManager.h"
#include "InitializationManager.h"
#include "AStarPathfinder.h"
#include "ThreadManager.h"
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

bool generateNodes(NodeManager &nodeManager, int gridSize);
bool initializeEntities(TrafficManager &trafficManager, NodeManager &nodeManager,
                        std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles);
void runSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                   std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager);
bool executeTaskQueue(std::queue<std::function<bool()>> &taskQueue);

#endif // MAIN_H
