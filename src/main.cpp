/* *************************************************
 * main.cpp
 * Purpose: Main program entrypoint.
 *          Implements trafficManager functions to change
 *          NPC data along a node system.
 ************************************************* */

// Standard
#include <iostream>

// Local
#include "include/main.h"
#include "include/functions.h"
#include "include/simulation.h"

void initializeNodes(std::vector<Node> &nodes)
{
    /* Creates circular connection between the current nodes
       by adding the next node in the list. */
    std::cout << "Initializing nodes..." << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        nodes[i].addNeighbor(&nodes[(i + 1) % nodes.size()]);
    }
}

void initializeNPCs(TrafficManager &trafficManager, std::vector<Node> &nodes, std::vector<NPC> &npcs)
{
    std::cout << "Initializing NPCs..." << std::endl;
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        npcs.emplace_back(i + 1, &nodes[i]);
        trafficManager.addNPC(&npcs.back());
    }
}

void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs)
{
    std::cout << "Simulating traffic..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        trafficManager.updateTraffic();

        // Check node for every npc in npcs and output its data
        for (const auto &npc : npcs)
        {
            std::cout << "NPC" << npc.getId() << " is at Node ";
            std::cout << npc.getCurrentNode()->getId() << std::endl;
        }
    }
}

int main()
{
    // Start the runtime clock at the beginning for accurate timing
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Starting program..." << std::endl;

    // Stores nodes and adds nodes to back of vector
    std::vector<Node> nodes;
    for (int i = 1; i <= 3; ++i)
    {
        nodes.emplace_back(i);
    }

    TrafficManager trafficManager;

    initializeNodes(nodes);
    std::vector<NPC> npcs; //  Stores NPCs
    initializeNPCs(trafficManager, nodes, npcs);

    simulateTraffic(trafficManager, npcs);

    std::cout << "Program finished." << std::endl;
    printExecutionTime(start);
    std::cout << "At ";
    printCurrentTime();
    return 0;
}