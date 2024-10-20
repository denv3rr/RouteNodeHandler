#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

#include "Node.h"
#include "TrafficManager.h"
#include "PathfindingManager.h"
#include "NPC.h"
#include "Vehicle.h"
#include <thread>
#include <mutex>
#include <vector>
#include <queue>

struct ProgressBar
{
    std::string entityType;
    int entityId;
    float progress;
};

extern std::queue<std::string> messageQueue;
extern std::mutex messageMutex;

void displayEntityStatus(const std::string &entityType, int entityId, bool success, const std::string &status);
void showProgressBar(const ProgressBar &bar, int position);
void clearProgressBar(int position);
void entityThreadFunction(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode, ProgressBar &progressBar, int position);
void runMultithreadedSimulation(TrafficManager &trafficManager, PathfindingManager &pathfindingManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles, NodeManager &nodeManager, int npcCount, int vehicleCount, std::atomic<bool> &nodesReady);

#endif // THREAD_MANAGER_H
