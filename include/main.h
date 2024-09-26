/* *************************************************
 * main.h
 * Purpose: main.cpp header file
 ************************************************* */
#ifndef MAIN_H
#define MAIN_H

// Standard
#include <iostream>
#include <vector>

// Local
#include "functions.h"
#include "NodeManager.h"
#include "TrafficManager.h"

void initializeNodes(std::vector<Node> &nodes);
void initializeNPCs(TrafficManager &trafficManager, std::vector<Node> &nodes, std::vector<NPC> &npcs);
void initializeVehicles(TrafficManager &trafficManager, std::vector<Node> &nodes, std::vector<Vehicle> &vehicles);
void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles);

#endif // MAIN_H