/* *************************************************
 * simulation.h
 * Purpose: simulation.cpp header file
 ************************************************* */
#ifndef SIMULATION_H
#define SIMULATION_H

// Standard
#include <vector>

// Local
#include "TrafficManager.h"

void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles);

#endif // SIMULATION_H