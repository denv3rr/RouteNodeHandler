#include "../include/Entity.h"

// Constructor
Entity::Entity(int id, Node *startNode) : id(id), currentNode(startNode) {}

// Virtual destructor
Entity::~Entity() {}

// Getter methods
int Entity::getId() const
{
    return id;
}

Node *Entity::getCurrentNode() const
{
    return currentNode;
}
