/* *************************************************
 * Node.h
 * Purpose: Node.cpp header file for creation of Node class
 ************************************************* */
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cmath> // For distance calculation

class Node
{
public:
    Node(int id, float x, float y, float z = 0.0f); // Init node id# and coordinates
    int getId() const;
    void addNeighbor(Node *neighbor);
    const std::vector<Node *> &getNeighbors() const;
    float getX() const;
    float getY() const;
    float getZ() const;
    float distanceTo(const Node *other) const; // For distance to nearest nodes

private:
    int id;
    float x, y, z;                 // 3D coordinates
    std::vector<Node *> neighbors; // Node neighbors vector
};

// Function to initialize the nodes with connections
void initializeNodes(std::vector<Node> &nodes);

// Function that randomly creates nodes
void createNode(int id);

#endif // NODE_H