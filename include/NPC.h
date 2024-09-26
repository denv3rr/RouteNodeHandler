#ifndef NPC_H
#define NPC_H

#include "Node.h"
#include <vector>

class NPC
{
public:
    NPC(int id, Node *startNode); // Constructor to initialize the NPC
    void move();                  // Simulate movement (simple for now)
    int getId() const;            // Return NPC ID
    Node *getCurrentNode() const; // Return the node where the NPC is currently located

private:
    int id;                   // NPC identifier
    Node *currentNode;        // Current node the NPC is on
    std::vector<Node *> path; // Path assigned to the NPC
};

#endif // NPC_H
