#ifndef NODE_H
#define NODE_H

#include <vector>
#include <memory> // For std::shared_ptr

class Node
{
private:
    int id;                                       // Node identifier
    int x, y, z;                                  // Coordinates for the node
    std::vector<std::shared_ptr<Node>> neighbors; // Connected neighbors
    bool blocked;                                 // Variable for indication of blocked status of a node

public:
    // Constructor
    Node(int nodeId, int xCoord, int yCoord, int zCoord);

    // Getters
    int getId() const;
    int getNodeId() const { return getId(); }
    int getX() const;
    int getY() const;
    int getZ() const;

    // Setters
    void setId(int newId);
    void setX(int newX);
    void setY(int newY);
    void setZ(int newZ);

    // Neighbor handling
    void addNeighbor(std::shared_ptr<Node> neighbor);
    std::vector<std::shared_ptr<Node>> getNeighbors() const;

    // Checking isBlocked() status
    bool isBlocked() const;
    void setBlocked(bool blockedStatus);
};

#endif
