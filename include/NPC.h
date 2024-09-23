/* *************************************************
 * NPC.h
 * Purpose: NPC header file for creation of NPC class.
 ************************************************* */
#ifndef NPC_H
#define NPC_H

#include "Node.h"

class NPC
{
public:
    NPC(int id, Node *startNode);
    int getId() const;
    Node *getCurrentNode() const;
    void moveToNode(Node *node);

private:
    int id;
    Node *currentNode;
};

#endif // NPC_H