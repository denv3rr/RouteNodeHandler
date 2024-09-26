/* *************************************************
 * simulation.h
 * Purpose: simulation.cpp header file
 ************************************************* */
#ifndef SIMULATION_H
#define SIMULATION_H

#include "TrafficManager.h"
#include <vector>

void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles);

#endif // SIMULATION_H