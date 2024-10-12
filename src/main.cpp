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
    std::cout << "\n\n\n";
    coloredSeperetLogoScrolling(34, 35);
    std::cout << "\n\n\n\033[32mRoute Node Handler\033[0m\n";
    std::cout << "\033[32mCopyright (c) 2024 Denver Clark\033[0m\n";
    std::cout << "\033[32mVisit the repo at: github.com/denv3rr/RouteNodeHandler\033[0m\n\n\n";

    NodeManager nodeManager;
    int nodeCount; // Set the node count
    int gridSize;  // Specify the size of the grid for nodes (cubed)

    std::cout << "Set the grid size (node count) for this simulation.\n\n";
    std::cout << "Grid size: ";
    std::cin >> gridSize;
    nodeCount = gridSize; // Set node count equal to grid size for simplicity
    std::cout << "\n\n";

    // Make sure node and grid count are at least 5 in order to build a functional grid
    if (nodeCount < 5 || gridSize < 5)
    {
        std::cerr << "\033[31mError: The node count and grid size must both be at least 5\nin order to build a sufficient grid.\033[0m\n";
        std::cout << "Your node count is set to: " << nodeCount << "\n";
        std::cout << "Your grid size is set to: " << gridSize << "\n";
        std::cout << "Re-run or refer to \033[32m'main.cpp'\033[0m (in \033[32m'src'\033[0m) to set these values manually.\n\n";
        std::cout << "\033[31mQuitting...\033[0m\n\n";

        return -1;
    }

    std::cout << "\n\n\033[32mStarting program...\033[0m\n\n";
    auto start = std::chrono::high_resolution_clock::now(); // Start program timer now

    std::cout << "\033[32mCreating nodes...\033[0m\n\n";
    std::srand(static_cast<unsigned>(std::time(0))); // Seed randomness for node positions
    nodeManager.createNodes(1.0f, gridSize);         // Initialize the specified number of nodes
    nodeManager.printNodes();                        // Optional: Print nodes for debugging

    std::cout << "\033[32m\nNodes created successfully.\033[0m\n\n";

    TrafficManager trafficManager;
    std::vector<NPC> npcs;         // Store NPCs
    std::vector<Vehicle> vehicles; // Store Vehicles

    int npcCount = 10;     // Number of NPCs to initialize
    int vehicleCount = 10; // Number of Vehicles to initialize

    initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
    initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);

    PathfindingManager pathfindingManager(nodeManager); // Declaration of pathfinding manager
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
