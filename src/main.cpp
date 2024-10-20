#include "main.h"

int main()
{
    // Section 1: Intro and User Input (shown only once)
    std::cout << "\n\n\n";
    coloredSeperetLogoScrolling(34, 35);
    std::cout << "\n\n\n\033[32mRoute Node Handler\033[0m\n";
    std::cout << "\033[32mCopyright (c) 2024 Denver Clark\033[0m\n";
    std::cout << "\033[32mVisit the repo at: github.com/denv3rr/RouteNodeHandler\033[0m\n\n\n";

    auto totalStart = std::chrono::high_resolution_clock::now(); // Total program start time

    bool keepRunning = true;
    while (keepRunning)
    {
    mainMenu:
        // Variables for simulation
        NodeManager nodeManager;
        TrafficManager trafficManager;
        std::vector<NPC> npcs;
        std::vector<Vehicle> vehicles;
        PathfindingManager pathfindingManager(nodeManager);

        // Set default pathfinding algorithm
        std::shared_ptr<IPathfindingAlgorithm> aStarAlgorithm = std::make_shared<AStarPathfinder>();
        pathfindingManager.setAlgorithm(aStarAlgorithm);

        // Prompt for user input (grid size, number of NPCs, vehicles, etc.)
        int gridSize, npcCount, vehicleCount;
        std::cout << "Set the grid size (node count) value for this simulation (at least 3).\n"
                  << "This 'gridSize' variable represents one of the three-dimensional values of your 3D cube grid.\n\n"
                  << "Grid size: ";

        while (!(std::cin >> gridSize) || gridSize < 3)
        {
            std::cerr << "\033[31mError: Invalid input. Please enter a numeric value for grid size (>= 3).\033[0m\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Grid size: ";
        }

        std::cout << "Enter number of NPCs: ";
        while (!(std::cin >> npcCount) || npcCount <= 0)
        {
            std::cerr << "\033[31mError: Invalid input. Please enter a numeric value greater than 0.\033[0m\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "NPC count: ";
        }

        std::cout << "Enter number of Vehicles: ";
        while (!(std::cin >> vehicleCount) || vehicleCount <= 0)
        {
            std::cerr << "\033[31mError: Invalid input. Please enter a numeric value greater than 0.\033[0m\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Vehicle count: ";
        }

        // Prompt for starting the simulation
        std::cout << "\nHit enter to start the simulation...";
        std::cin.ignore(); // Flush newline
        std::cin.get();    // Wait for Enter key

        // Section 2: Run simulation with only progress bars showing
        auto simulationStart = std::chrono::high_resolution_clock::now(); // Start of each simulation run

        std::queue<std::function<bool()>> taskQueue;
        taskQueue.push([&]()
                       { return generateNodes(nodeManager, gridSize); });
        taskQueue.push([&]()
                       { return initializeEntities(trafficManager, nodeManager, npcs, vehicles, npcCount, vehicleCount); });
        taskQueue.push([&]()
                       {
            runSimulation(trafficManager, pathfindingManager, npcs, vehicles, nodeManager);
            return true; });

        if (!executeTaskQueue(taskQueue))
        {
            std::cerr << "\033[31mProgram terminated due to task failure.\033[0m\n";
            return -1;
        }

        // Section 3: Post-simulation menu
        while (true)
        {
            std::cout << "\nSimulation completed. Select what you'd like to do next:\n"
                      << "1. View Node Creation Logs\n"
                      << "2. View Neighbor Creation Logs\n"
                      << "3. View Pathfinding Logs\n"
                      << "4. View Final Print Log\n"
                      << "5. Return to Main Menu\n"
                      << "6. Quit Program\n"
                      << "Enter option: ";

            int option;
            std::cin >> option;

            switch (option)
            {
            case 1:
                printNodeCreationLogs();
                break;
            case 2:
                printNeighborCreationLogs();
                break;
            case 3:
                printPathfindingLogs();
                break;
            case 4:
                printFinalLog();
                break;
            case 5:
                goto mainMenu; // Return to the main menu by jumping to the start of the loop
            case 6:
                keepRunning = false; // Exit the loop to quit the program
                break;
            default:
                std::cerr << "\033[31mInvalid option. Try again.\033[0m\n";
                break;
            }
        }

        // Display time for the individual simulation run
        auto simulationEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> simulationDuration = simulationEnd - simulationStart;
        std::cout << "Simulation duration: " << simulationDuration.count() << " seconds\n";
    }

    // Footer and closing
    auto totalEnd = std::chrono::high_resolution_clock::now(); // Total program end time
    std::chrono::duration<double> totalDuration = totalEnd - totalStart;
    std::cout << "\n*************************\n\n";
    std::cout << "\033[32mProgram finished.\033[0m\n";
    std::cout << "Total program duration: " << totalDuration.count() << " seconds\n";
    printCurrentTime();
    std::cout << "\n\n\n";
    coloredSeperetLogoScrolling(34, 35);
    std::cout << "\n\n\n";

    return 0;
}