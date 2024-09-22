/* *************************************************
 * main.h
 * Purpose: main.cpp header file
 ************************************************* */
#ifndef MAIN_H
#define MAIN_H

#include "TrafficManager.h"

void initializeNodes(Node &node1, Node &node2, Node &node3);
void initializeNPCs(TrafficManager &trafficManager, Node &node1, Node &node2);
void simulateTraffic(TrafficManager &trafficManager, NPC &npc1, NPC &npc2);

#endif // MAIN_H