#include "../include/main.h"

int main()
{
    // Section 1: Intro and Node Generation
    std::cout << "\n\n\n";
    coloredSeperetLogoScrolling(34, 35);
    std::cout << "\n\n\n\033[32mRoute Node Handler\033[0m\n";
    std::cout << "\033[32mCopyright (c) 2024 Denver Clark\033[0m\n";
    std::cout << "\033[32mVisit the repo at: github.com/denv3rr/RouteNodeHandler\033[0m\n\n\n";

    NodeManager nodeManager;
    TrafficManager trafficManager;
    std::vector<NPC> npcs;
    std::vector<Vehicle> vehicles;
    PathfindingManager pathfindingManager(nodeManager);

    // Prompt for user input
    int gridSize;
    std::cout << "Set the grid size (node count) value for this simulation.\n"
              << "This 'gridSize' variable represents one of the three-dimensional values of your 3D cube grid.\n"
              << "Ex: (gridSize * gridSize * gridSize) is used to create your 3D grid.\n\n"
              << "Grid size: ";

    while (!(std::cin >> gridSize))
    {
        std::cerr << "\033[31mError: Invalid input. Please enter a numeric value for grid size.\033[0m\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Grid size: ";
    }

    if (gridSize < 3)
    {
        std::cerr << "\033[31mError: Grid size must be at least 3 to create a valid simulation grid.\033[0m\n";
        return -1;
    }

    // Task queue and execution
    std::queue<std::function<bool()>> taskQueue;

    // Section 2: Queue tasks for execution
    taskQueue.push([&]()
                   { return generateNodes(nodeManager, gridSize); }); // Pass gridSize to the generateNodes function
    taskQueue.push([&]()
                   { return initializeEntities(trafficManager, nodeManager, npcs, vehicles); });
    taskQueue.push([&]()
                   { runSimulation(trafficManager, pathfindingManager, npcs, vehicles, nodeManager);
                        return true; });

    // Execute tasks
    auto start = std::chrono::high_resolution_clock::now();
    if (!executeTaskQueue(taskQueue))
    {
        std::cerr << "\033[31mProgram terminated due to task failure.\033[0m\n";
        return -1;
    }

    // Footer and clocks
    std::cout << "\n*************************\n\n";
    std::cout << "\033[32mProgram finished.\033[0m\n";
    printExecutionTime(start);
    std::cout << "At: ";
    printCurrentTime();
    std::cout << "\n\n\n";
    coloredSeperetLogoScrolling(34, 35);
    std::cout << "\n\n\n";

    return 0;
}