/* *************************************************
 * simulation.cpp
 * Purpose: simulation logic for interacting with traffic manager
 *          and created objects
 ************************************************* */

// Standard
#include <iostream>

// Local
#include "simulation.h"

void simulateTraffic(TrafficManager &trafficManager, std::vector<NPC> &npcs, std::vector<Vehicle> &vehicles)
{
    /* *************************************************
     * Simulate Traffic function
     * Purpose: Handles logic for simulation running during main program.
     *          Currently loops through a Node vector created for vehicles,
     *          NPCs, and other object classes and updates the data along
     *          with the trafficManager as well.
     ************************************************* */
    std::cout << "Simulating traffic..." << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        // update traffic manager at start of every iteration
        trafficManager.updateTraffic();

        // updates for NPCs
        for (const auto &npc : npcs)
        {
            std::cout << "NPC " << npc.getId() << " is at Node " << npc.getCurrentNode()->getId() << std::endl;
        }

        // updates for vehicles
        for (const auto &vehicle : vehicles)
        {
            std::cout << "Vehicle " << vehicle.getId() << " is at Node " << vehicle.getCurrentNode()->getId() << std::endl;
        }
    }
}