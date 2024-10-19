#include "../include/main.h"

int main()
{
    std::cout << "\n\n\n";
    coloredSeperetLogoScrolling(34, 35);
    std::cout << "\n\n\n\033[32mRoute Node Handler\033[0m\n";
    std::cout << "\033[32mCopyright (c) 2024 Denver Clark\033[0m\n";
    std::cout << "\033[32mVisit the repo at: github.com/denv3rr/RouteNodeHandler\033[0m\n\n\n";

    NodeManager nodeManager;
    int nodeCount;
    int gridSize;

    std::cout << "Set the grid size (node count) value for this simulation.\n"
              << "This 'gridSize' variable represents one of the three dimensional values of your 3D cube grid.\n"
              << "Ex: (gridSize * gridSize * gridSize) is used to create your 3D grid.\n\n"
              << "Grid size: ";

    while (!(std::cin >> gridSize))
    {
        std::cerr << "\033[31mError: Invalid input. Please enter a numeric value for grid size.\033[0m\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Grid size: ";
    }

    nodeCount = gridSize;

    if (nodeCount < 5 || gridSize < 5)
    {
        std::cerr << "\033[31mError: The node count and grid size must both be at least 5\n"
                  << "in order to build a sufficient grid.\033[0m\n";
        std::cout << "Your node count is set to: " << nodeCount << "\n";
        std::cout << "Your grid size is set to: " << gridSize << "\n";
        std::cout << "Re-run or refer to \033[32m'main.cpp'\033[0m (in \033[32m'src'\033[0m) to set these values manually.\n\n"
                  << "\033[31mQuitting...\033[0m\n\n";
        return -1;
    }

    std::cout << "\n\n\033[32mStarting program...\033[0m\n\n";
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\033[32mCreating nodes...\033[0m\n\n";
    std::srand(static_cast<unsigned>(std::time(0)));
    nodeManager.createNodes(1.0f, gridSize);
    nodeManager.printNodes();

    std::cout << "\033[32m\nNodes created successfully.\033[0m\n\n";

    TrafficManager trafficManager;
    std::vector<NPC> npcs;
    std::vector<Vehicle> vehicles;

    int npcCount = 10;
    int vehicleCount = 10;

    initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
    initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);

    PathfindingManager pathfindingManager(nodeManager);
    int choice;
    if (choice == 1)
        pathfindingManager.setAlgorithm(std::make_shared<AStarPathfinder>());
    else
        pathfindingManager.setAlgorithm(std::make_shared<DijkstraPathfinder>());

    runMultithreadedSimulation(trafficManager, pathfindingManager, npcs, vehicles, nodeManager, npcCount, vehicleCount);

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
