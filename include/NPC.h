/* *************************************************
 * NPC.h
 * Purpose: NPC header file for creation of NPC class.
 ************************************************* */
#ifndef NPC_H
#define NPC_H

#include "Node.h"
#include "TrafficManager.h"
#include <vector>

class NPC
{
public:
    NPC(int id, Node *startNode);
    int getId() const;
    Node *getCurrentNode() const;
    void moveToNode(Node *node);
};

void initializeNPCs(TrafficManager &trafficManager, std::vector<Node> &nodes, std::vector<NPC> &npcs);

#endif // NPC_H