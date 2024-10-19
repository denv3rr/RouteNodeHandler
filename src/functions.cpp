#include "../include/functions.h"
#include "../include/NPC.h"                   // For NPC class
#include "../include/Vehicle.h"               // For Vehicle class
#include "../include/InitializationManager.h" // For initializeNPCs, initializeVehicles
#include "../include/ThreadManager.h"         // For runMultithreadedSimulation
#include "../include/TrafficManager.h"
#include "../include/NodeManager.h"
#include "../include/PathfindingManager.h"
#include <queue>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

// Print the execution time since start
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start)
{
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "Execution time: " << duration << " ms (" << duration / 1000 << " sec)\n";
}

// Print the current local time
void printCurrentTime()
{
  auto now = std::chrono::system_clock::now();
  std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::cout << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S\n");
}

bool generateNodes(NodeManager &nodeManager, int gridSize)
{
  std::cout << "\033[32mStarting node generation...\033[0m\n";
  nodeManager.createNodes(1.0f, gridSize);
  std::cout << "\033[32mNodes created successfully.\033[0m\n";
  return true;
}

bool initializeEntities(TrafficManager &trafficManager, NodeManager &nodeManager,
                        std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles)
{
  int npcCount = 10, vehicleCount = 10;
  std::cout << "\033[32mInitializing NPCs and Vehicles...\033[0m\n";
  initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
  initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);
  std::cout << "\033[32mEntities initialized successfully.\033[0m\n";
  return true;
}

void runSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                   std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager)
{
  std::cout << "\033[32mRunning pathfinding simulation...\033[0m\n";

  std::atomic<bool> nodesReady(true);

  try
  {
    runMultithreadedSimulation(trafficManager, pathfindingManager, npcs, vehicles, nodeManager, 3, 3, nodesReady);
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception in simulation: " << e.what() << std::endl;
    // Handle the exception appropriately, but no return statement is needed here.
  }
}

bool executeTaskQueue(std::queue<std::function<bool()>> &taskQueue)
{
  while (!taskQueue.empty())
  {
    auto task = taskQueue.front();
    taskQueue.pop();
    if (!task())
    {
      std::cerr << "\033[31mError: Task failed. Quitting...\033[0m\n";
      return false;
    }
  }
  return true;
}

// Function to print the logo with specified colors and scrolling effect
void coloredSeperetLogoScrolling(int colorCode1, int colorCode2)
{
  // First part of the logo
  std::string logoPart1 = R"(
 __   ____  ___   ____  ___   ____ _____ 
( (` | |_  | |_) | |_  | |_) | |_   | |  )";

  // Second part of the logo
  std::string logoPart2 = R"(_)_) |_|__ |_|   |_|__ |_| \ |_|__  |_|  
    
)";

  // Set color for first part
  std::cout << "\033[" << colorCode1 << "m"; // Start color 1

  // Print first part character by character
  for (char c : logoPart1)
  {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(0)); // Adjust delay as needed
  }

  // Reset color
  std::cout << "\033[0m"; // End color 1

  // Newline before second part
  std::cout << "\n";

  // Set color for second part
  std::cout << "\033[" << colorCode2 << "m"; // Start color 2

  // Print second part character by character
  for (char c : logoPart2)
  {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(0)); // Adjust delay as needed
  }

  // Reset color
  std::cout << "\033[0m"; // End color 2
}