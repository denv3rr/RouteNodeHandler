/* *************************************************
 * main.cpp
 * Purpose: Main program entrypoint.
 *          Implements trafficManager functions to change
 *          NPC data along a node system.
 ************************************************* */

// Standard
#include <iostream>
#include <chrono>
#include <ctime>

// Local
#include "../include/functions.h"
#include "main.h"
#include "simulation.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    char input;

    // Start the runtime clock at the beginning for accurate timing
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\n\nStarting program..." << std::endl;

    // Stores nodes and adds nodes to back of vector
    std::vector<Node> nodes;
    nodes.emplace_back(1, 0.0f, 0.0f);
    nodes.emplace_back(2, 1.0f, 0.0f);
    nodes.emplace_back(3, 0.0f, 1.0f);

    TrafficManager trafficManager;
    std::vector<NPC> npcs;         //  Stores NPCs
    std::vector<Vehicle> vehicles; // Stores Vehicles

    initializeNodes(nodes);
    initializeNPCs(trafficManager, nodes, npcs);
    initializeVehicles(trafficManager, nodes, vehicles);

    simulateTraffic(trafficManager, npcs, vehicles);

    std::cout << "\n*************************\n\n";
    std::cout << "Program finished." << std::endl;
    printExecutionTime(start);
    std::cout << "At: ";
    printCurrentTime();
    return 0;
}