/* *************************************************
 * main.cpp
 * Purpose: Main program entrypoint.
 *          Implements trafficManager functions to change
 *          NPC data along a node system.
 ************************************************* */

// Standard
#include <iostream>

// Local
#include "main.h"

void initializeNodes(Node &node1, Node &node2, Node &node3)
{
    /* Creates circular connection between the current nodes
    by adding the next node in the list to the node making
    the call to add the neighbor. */

    node1.addNeighbor(&node2);
    node2.addNeighbor(&node3);
    node3.addNeighbor(&node1);
}

void initializeNPCs(TrafficManager &trafficManager, Node &node1, Node &node2)
{
}

void simulateTraffic(TrafficManager &trafficManager, NPC &npc1, NPC &npc2)
{
}

int main()
{
}