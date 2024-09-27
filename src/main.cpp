/* *************************************************
 * main.cpp
 * Purpose: Main entry point for the Node Route Simulation
 ************************************************* */

#include "../include/main.h"
#include "../include/Node.h"
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
    std::cout << "\n\n\033[32mStarting program...\033[0m\n"
              << std::endl;

    NodeManager nodeManager;
    int gridSize = 20;                          // 20x20x20 grid => 8000 nodes
    float spacing = 1.0f;                       // Adjust this node spacing as needed!
    nodeManager.createNodes(spacing, gridSize); // Initialize the specified number of nodes
    nodeManager.printNodes();                   // Optional: Print nodes for debugging

    TrafficManager trafficManager;
    std::vector<NPC> npcs;         // Store NPCs
    std::vector<Vehicle> vehicles; // Store Vehicles

    int npcCount = 10;     // Number of NPCs to initialize
    int vehicleCount = 10; // Number of Vehicles to initialize

    initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
    initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);

    simulateTraffic(trafficManager, npcs, vehicles, nodeManager);

    // Initialization of Start and End nodes
    std::shared_ptr<Node> startNode = nodeManager.getNodes()[0];
    std::shared_ptr<Node> goalNode = nodeManager.getNodes()[99];
    std::vector<Node *> path = nodeManager.findPath(startNode, goalNode);

    std::cout << "\nPath from Node " << startNode->getId() << " to Node " << goalNode->getId() << ":\n";
    for (Node *node : path)
    {
        std::cout << "Node ID: " << node->getId() << " at (" << node->getX() << ", " << node->getY() << ", " << node->getZ() << ")\n";
    }

    std::cout << "\n*************************\n\n";
    std::cout << "\033[32mProgram finished." << std::endl;
    printExecutionTime(start);
    std::cout << "\033[0m";
    std::cout << "At: ";
    printCurrentTime();

    return 0;
}
