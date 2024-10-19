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
#include "NPC.h"     // Include the definition of NPC
#include "Vehicle.h" // Include the definition of Vehicle

// Utility functions for time calculations and printing
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start);
void printCurrentTime();
void coloredSeperetLogoScrolling(int, int);

// Functions related to the simulation process
bool generateNodes(NodeManager &nodeManager);
bool initializeEntities(TrafficManager &trafficManager, NodeManager &nodeManager,
                        std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles);
void runSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                   std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager);
bool executeTaskQueue(std::queue<std::function<bool()>> &taskQueue);

#endif // FUNCTIONS_H
