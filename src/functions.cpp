#include "functions.h"
#include "NPC.h"
#include "Vehicle.h"
#include "InitializationManager.h"
#include "ThreadManager.h"
#include "TrafficManager.h"
#include "NodeManager.h"
#include "PathfindingManager.h"
#include <queue>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

// Print execution time
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start)
{
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "Execution time: " << duration << " ms (" << duration / 1000 << " sec)\n";
}

// Print the current time
void printCurrentTime()
{
  auto now = std::chrono::system_clock::now();
  std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::cout << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S\n");
}

// Generate nodes and log the process
bool generateNodes(NodeManager &nodeManager, int gridSize)
{
  std::cout << "\033[32mStarting node generation...\033[0m\n";
  nodeManager.createNodes(1.0f, gridSize);
  std::cout << "\033[32m\nNodes created successfully.\033[0m\n\n";
  return true;
}

// Initialize NPCs and Vehicles
bool initializeEntities(TrafficManager &trafficManager, NodeManager &nodeManager,
                        std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles,
                        int npcCount, int vehicleCount)
{
  std::cout << "\033[32mInitializing " << npcCount << " NPCs and " << vehicleCount << " Vehicles...\033[0m\n";
  initializeNPCs(trafficManager, nodeManager.getNodes(), npcs, npcCount);
  initializeVehicles(trafficManager, nodeManager.getNodes(), vehicles, vehicleCount);
  std::cout << "\033[32mEntities initialized successfully.\033[0m\n";
  return true;
}

// Run simulation and display progress bars
void runSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager,
                   std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager)
{
  std::cout << "\033[32m\nRunning pathfinding simulation...\033[0m\n";
  std::atomic<bool> nodesReady(true);

  try
  {
    runMultithreadedSimulation(trafficManager, pathfindingManager, npcs, vehicles, nodeManager, npcs.size(), vehicles.size(), nodesReady);
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception in simulation: " << e.what() << "\n";
  }
}

// Execute task queue
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

// Log printing functions
void printNodeCreationLogs() { std::cout << "Node creation logs...\n"; }
void printNeighborCreationLogs() { std::cout << "Neighbor creation logs...\n"; }
void printPathfindingLogs() { std::cout << "Pathfinding logs...\n"; }
void printFinalLog() { std::cout << "Final log...\n"; }

// Colored logo printing
void coloredSeperetLogoScrolling(int colorCode1, int colorCode2)
{
  std::string logoPart1 = R"(
 __   ____  ___   ____  ___   ____ _____ 
( (` | |_  | |_) | |_  | |_) | |_   | |  )";
  std::string logoPart2 = R"(_)_) |_|__ |_|   |_|__ |_| \ |_|__  |_|  
)";

  std::cout << "\033[" << colorCode1 << "m";
  for (char c : logoPart1)
  {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(0));
  }
  std::cout << "\033[0m\n\033[" << colorCode2 << "m";
  for (char c : logoPart2)
  {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(0));
  }
  std::cout << "\033[0m\n";
}
