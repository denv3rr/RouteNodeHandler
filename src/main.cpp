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
    {
        // Logo / Startup

        // Break
        std::cout << "\n\n\n";

        // Red and Yellow
        // coloredSeperetLogo(31, 33);

        // Green and Cyan
        coloredSeperetLogoScrolling(34, 35);

        // Yellow and Magenta
        // coloredSeperetLogo(33, 35);

        // std::cout << "\n\n";

        // RNH Logo
        // coloredLogoScrolling(37, 35, 34, 32);

        std::cout << "\n\n\n";

        sleep(1);
    }

    std::srand(static_cast<unsigned>(std::time(0))); // Seed randomness for node positions

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "\n\n\033[32mStarting program...\033[0m\n"
              << std::endl;

    NodeManager nodeManager;
    int nodeCount = 10; // Set the node count for a 20x20x20 grid, or adjust this value as needed
    int gridSize = 10;  // Specify the size of the grid for nodes

    std::cout << "\033[32mCreating nodes...\033[0m" << std::endl;
    nodeManager.createNodes(1.0f, gridSize); // Initialize the specified number of nodes
    nodeManager.printNodes();                // Optional: Print nodes for debugging

    std::cout << "\033[32m\nNodes created successfully.\033[0m" << std::endl;

    TrafficManager trafficManager;
    std::vector<NPC> npcs;         // Store NPCs
    std::vector<Vehicle> vehicles; // Store Vehicles

    int npcCount = 10;     // Number of NPCs to initialize
    int vehicleCount = 10; // Number of Vehicles to initialize

    initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
    initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);

    PathfindingManager pathfindingManager;                                // Declaration of pathfinding manager
    pathfindingManager.setAlgorithm(std::make_shared<AStarPathfinder>()); // Ensures the algorithm is set
    simulateTraffic(trafficManager, npcs, vehicles, nodeManager, pathfindingManager);

    // Initialization of Start and End nodes
    std::shared_ptr<Node> startNode = nodeManager.getNodes()[0];
    std::shared_ptr<Node> goalNode = nodeManager.getNodes()[99];

    std::cout << "\033[32mFinding path from Node " << startNode->getId() << " to Node " << goalNode->getId() << "...\033[0m" << std::endl;

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
    // coloredLogoScrolling(37, 35, 34, 32);

    std::cout << "\n\n\n";

    return 0;
}
