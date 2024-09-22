/* *************************************************
 * NPC.cpp
 * Purpose: creates an instance of NPC class.
 ************************************************* */
#include "NPC.h"

NPC::NPC(int id, Node *startNode) : id(id), currentNode(startNode) {}

int NPC::getId() const
{
    return id;
}

Node *NPC::getCurrentNode() const
{
    return currentNode;
}

void NPC::moveToNode(Node *node)
{
    currentNode = node;
}