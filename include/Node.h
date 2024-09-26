#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:
    Node(int id, float x, float y, float z = 0.0f); // Constructor to initialize node ID and coordinates
    int getId() const;
    void addNeighbor(Node *neighbor);                // Add a neighboring node
    const std::vector<Node *> &getNeighbors() const; // Return all neighbors
    float getX() const;
    float getY() const;
    float getZ() const;

private:
    int id;
    float x, y, z;                 // 3D coordinates
    std::vector<Node *> neighbors; // Neighbors of this node
};

#endif // NODE_H