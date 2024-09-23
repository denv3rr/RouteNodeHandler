/* *************************************************
 * main.cpp
 * Purpose: Main program entrypoint.
 *          Implements trafficManager functions to change
 *          NPC data along a node system.
 ************************************************* */

// Standard
#include <iostream>

// Local
#include "main.h"
#include "functions.h"
#include "simulation.h"
#include "Vehicle.h"

int main()
{
    // Start the runtime clock at the beginning for accurate timing
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Starting program..." << std::endl;

    // Stores nodes and adds nodes to back of vector
    std::vector<Node> nodes;
    for (int i = 1; i <= 3; ++i)
    {
        nodes.emplace_back(i);
    }

    TrafficManager trafficManager;
    std::vector<NPC> npcs;         //  Stores NPCs
    std::vector<Vehicle> vehicles; // Stores Vehicles

    initializeNodes(nodes);
    initializeNPCs(trafficManager, nodes, npcs);
    initializeVehicles(trafficManager, nodes, vehicles);

    simulateTraffic(trafficManager, npcs, vehicles);

    std::cout << "Program finished." << std::endl;
    printExecutionTime(start);
    std::cout << "At ";
    printCurrentTime();
    return 0;
}