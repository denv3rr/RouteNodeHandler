#include "Entity.h"

// Constructor
Entity::Entity(int id, std::shared_ptr<Node> startNode) : id(id), currentNode(startNode) {}

// Virtual destructor
Entity::~Entity() {}

// Getter methods
int Entity::getId() const
{
    return id;
}

std::shared_ptr<Node> Entity::getCurrentNode() const
{
    return currentNode;
}
