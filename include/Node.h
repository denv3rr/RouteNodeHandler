/* *************************************************
 * Node.h
 * Purpose: Node.cpp header file for creation of Node class.
 *          Includes finding distance between nodes, getting coords
 *          of a particular node, creating nodes, etc.
 ************************************************* */
#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:
    Node(int id, float x, float y, float z = 0.0f); // Node constructor
    int getId() const;
    void addNeighbor(Node *neighbor);
    const std::vector<Node *> &getNeighbors() const;
    float getX() const;
    float getY() const;
    float getZ() const;

private:
    int id;
    float x, y, z;                 // 3D coordinates of the node
    std::vector<Node *> neighbors; // List of neighboring nodes
};

// Function to initialize the nodes with connections
void initializeNodes(std::vector<Node> &nodes);

// Function that randomly creates nodes
void createNode(int id);

#endif // NODE_H