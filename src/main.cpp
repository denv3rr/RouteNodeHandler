/* *************************************************
 * main.cpp
 * Purpose: Main entry point for the Node Route Simulation
 ************************************************* */

// Local
#include "../include/main.h"
#include "../include/Node.h"
#include "../include/NodeManager.h"
#include "../include/TrafficManager.h"
#include "../include/simulation.h"
#include "../include/functions.h"

// Standard
#include <iostream>
#include <iomanip> // For std::setprecision

int main()
{
    std::srand(static_cast<unsigned>(std::time(0))); // Seed randomness for node positions

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "\n\n\033[32mStarting program...\033[0m\n";

    NodeManager nodeManager;
    int nodeCount = 5; // Set the node count
    int gridSize = 5;  // Specify the size of the grid for nodes (cubed)

    std::cout << "\033[32mCreating nodes...\033[0m\n";
    nodeManager.createNodes(1.0f, gridSize); // Initialize the specified number of nodes
    nodeManager.printNodes();                // Optional: Print nodes for debugging

    std::cout << "\033[32m\nNodes created successfully.\033[0m\n";

    TrafficManager trafficManager;
    std::vector<NPC> npcs;         // Store NPCs
    std::vector<Vehicle> vehicles; // Store Vehicles

    int npcCount = 10;     // Number of NPCs to initialize
    int vehicleCount = 10; // Number of Vehicles to initialize

    initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
    initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);

    PathfindingManager pathfindingManager; // Declaration of pathfinding manager
    int choice;
    if (choice == 1)
        pathfindingManager.setAlgorithm(std::make_shared<AStarPathfinder>());
    else
        pathfindingManager.setAlgorithm(std::make_shared<DijkstraPathfinder>());

    simulateTraffic(trafficManager, npcs, vehicles, nodeManager, pathfindingManager);

    // Initialization of Start and End nodes
    std::shared_ptr<Node> startNode = nodeManager.getNodes()[0];
    std::shared_ptr<Node> goalNode = nodeManager.getNodes()[99];

    std::cout << "\033[32mFinding path from Node " << startNode->getId() << " to Node " << goalNode->getId() << "...\033[0m\n";

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

    std::cout << "\n\n\n";

    coloredSeperetLogoScrolling(34, 35);

    std::cout << "\n\n\n";

    return 0;
}
