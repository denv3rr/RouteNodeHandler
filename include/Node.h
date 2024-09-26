/* *************************************************
 * Node.h
 * Purpose: Node.cpp header file for creation of Node class
 ************************************************* */
#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:
    Node(int id);
    int getId() const;
    void addNeighbor(Node *neighbor);
    const std::vector<Node *> &getNeighbors() const;

private:
    int id;
    std::vector<Node *> neighbors; // Node neighbors vector
};

void initializeNodes(std::vector<Node> &nodes);

#endif // NODE_H