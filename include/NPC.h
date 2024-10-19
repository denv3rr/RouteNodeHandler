#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include "Node.h"
#include <memory>

class NPC : public Entity
{
public:
    NPC(int id, std::shared_ptr<Node> startNode);
    ~NPC() override;                                 // Override the destructor
    void move() override;                            // Override the move function
    void setPath(std::vector<Node *> path) override; // Override setPath
};

#endif // NPC_H
