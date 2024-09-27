#ifndef ENTITY_H
#define ENTITY_H

#include "Node.h"
#include <vector>

class Entity
{
public:
    Entity(int id, Node *startNode); // Constructor
    virtual ~Entity();               // Virtual destructor to ensure proper cleanup

    virtual void move() = 0;                            // Pure virtual method to be implemented by derived classes
    virtual void setPath(std::vector<Node *> path) = 0; // Pure virtual method

    // Getter methods (if needed)
    int getId() const;            // Return entity ID
    Node *getCurrentNode() const; // Return current node

protected:
    int id;
    Node *currentNode;
    std::vector<Node *> path; // Store the path to move along
};

#endif // ENTITY_H
