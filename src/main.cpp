/* *************************************************
 * main.cpp
 * Purpose: Main entry point for the Node Route Simulation
 ************************************************* */

#include "../include/main.h"
#include "../include/NodeManager.h"
#include "../include/TrafficManager.h"
#include "../include/simulation.h"
#include "../include/functions.h"

#include <iostream>
#include <iomanip> // For std::setprecision

int main()
{
    std::srand(static_cast<unsigned>(std::time(0))); // Seed randomness for node positions

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "\n\nStarting program..." << std::endl;

    // Create NodeManager and initialize nodes with random positions
    NodeManager nodeManager;
    int nodeCount = 20;                           // Specify the desired number of nodes to generate
    nodeManager.initializeNodes(nodeCount, 1.0f); // Initialize the specified number of nodes
    nodeManager.printNodes();                     // Optional: Print nodes for debugging

    // Create TrafficManager and initialize NPCs and Vehicles
    TrafficManager trafficManager;
    std::vector<NPC> npcs;         // Store NPCs
    std::vector<Vehicle> vehicles; // Store Vehicles

    int npcCount = 10;     // Number of NPCs to initialize
    int vehicleCount = 10; // Number of Vehicles to initialize

    // Initialize NPCs and Vehicles with the updated counts
    initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
    initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);

    // Run the simulation
    simulateTraffic(trafficManager, npcs, vehicles);

    // Print completion message and execution time
    std::cout << "\n*************************\n\n";
    std::cout << "Program finished." << std::endl;
    printExecutionTime(start);
    std::cout << "At: ";
    printCurrentTime();

    return 0;
}
