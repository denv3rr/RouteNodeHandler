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
    Node(int id, float x, float y, float z = 0.0f); // init node id# and coordinates
    void moveRandomly();
    int getId() const;
    void addNeighbor(Node *neighbor);
    const std::vector<Node *> &getNeighbors() const;
    float getX() const;
    float getY() const;
    float getZ() const;

private:
    int id;
    float x, y, z;                 // 3D coordinates
    std::vector<Node *> neighbors; // Node neighbors vector
};

void initializeNodes(std::vector<Node> &nodes);
void createNode(int id);

#endif // NODE_H