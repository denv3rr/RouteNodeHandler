#ifndef ENTITY_H
#define ENTITY_H

#include "Node.h"
#include <vector>
#include <memory> // For std::shared_ptr

class Entity
{
public:
    Entity(int id, std::shared_ptr<Node> startNode); // Constructor
    virtual ~Entity();                               // Virtual destructor to ensure proper cleanup

    virtual void move() = 0;                            // Pure virtual method to be implemented by derived classes
    virtual void setPath(std::vector<Node *> path) = 0; // Pure virtual method

    // Getter methods
    int getId() const;                            // Return entity ID
    std::shared_ptr<Node> getCurrentNode() const; // Return current node

protected:
    int id;
    std::shared_ptr<Node> currentNode; // Use shared_ptr for currentNode
    std::vector<Node *> path;          // Store the path to move along
};

#endif // ENTITY_H
