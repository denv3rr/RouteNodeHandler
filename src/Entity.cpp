#include "../include/Entity.h"

// Constructor for Entity
Entity::Entity(int id, Node *startNode) : id(id), currentNode(startNode) {}

// Get the entity's ID
int Entity::getId() const
{
    return id;
}

// Get the current node the entity is at
Node *Entity::getCurrentNode() const
{
    return currentNode;
}
