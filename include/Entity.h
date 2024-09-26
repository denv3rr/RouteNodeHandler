#ifndef ENTITY_H
#define ENTITY_H

#include "Node.h"

class Entity
{
public:
    Entity(int id, Node *startNode) : id(id), currentNode(startNode) {}

    virtual ~Entity() = default;

    virtual void move() = 0;                             // Pure virtual function for movement logic
    int getId() const { return id; }                     // Return the ID of the entity
    Node *getCurrentNode() const { return currentNode; } // Get the current node

protected:
    int id;            // Unique ID for the entity
    Node *currentNode; // Pointer to the current node of the entity
};

#endif // ENTITY_H
