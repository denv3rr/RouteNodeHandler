#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>
#include <thread>
#include <functional>
#include <queue>
#include <atomic>
#include "../include/NodeManager.h"
#include "../include/TrafficManager.h"
#include "../include/PathfindingManager.h"
#include "NPC.h"
#include "Vehicle.h"

// Utility functions
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start);
void printCurrentTime();
void coloredSeperetLogoScrolling(int, int);

// Log printing functions
void printNodeCreationLogs();
void printNeighborCreationLogs();
void printPathfindingLogs();
void printFinalLog();

// Simulation process functions
bool generateNodes(NodeManager &nodeManager, int gridSize);
bool initializeEntities(TrafficManager &trafficManager, NodeManager &nodeManager,
                        std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, int npcCount, int vehicleCount);
void runSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                   std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager);
bool executeTaskQueue(std::queue<std::function<bool()>> &taskQueue);

#endif // FUNCTIONS_H
