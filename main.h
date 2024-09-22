/* *************************************************
 * main.h
 * Purpose: main.cpp header file
 ************************************************* */
#ifndef MAIN_H
#define MAIN_H

#include "TrafficManager.h"

void initializeNodes(std::vector<Node> &nodes);
void initializeNPCs(TrafficManager &trafficManager, std::vector<Node> &nodes);
void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs);

#endif // MAIN_H