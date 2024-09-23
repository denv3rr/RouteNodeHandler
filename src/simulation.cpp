/* *************************************************
 * simulation.cpp
 * Purpose: simulation logic for interacting with traffic manager
 *          and created objects
 ************************************************* */

// Standard
#include <iostream>

// Local
#include "include/simulation.h"

void simulateTraffic()
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
        }

        // updates for vehicles
        for (const auto &vehicle : vehicles)
        {
        }
    }
}