#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include "Node.h"

class NPC : public Entity
{
public:
    NPC(int id, Node *startNode);
    ~NPC() override;                                 // Override the destructor
    void move() override;                            // Override the move function
    void setPath(std::vector<Node *> path) override; // Override setPath
};

#endif // NPC_H
