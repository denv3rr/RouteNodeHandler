#ifndef ENTITY_H
#define ENTITY_H

#include "Node.h"

class Entity
{
protected:
    int id;
    Node *currentNode;

public:
    // Constructor to initialize entity with an ID and starting node
    Entity(int id, Node *startNode);

    // Get the entity's ID
    virtual int getId() const;

    // Get the current node the entity is at
    virtual Node *getCurrentNode() const;

    // Move the entity to the next node (defined in derived classes)
    virtual void move() = 0; // Pure virtual function
};

#endif // ENTITY_H
