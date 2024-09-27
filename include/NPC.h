#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include <vector>

class NPC : public Entity
{
private:
    std::vector<Node *> path; // The path for NPC to follow

public:
    NPC(int id, Node *startNode);

    void move() override; // Override the pure virtual function from Entity
};

#endif // NPC_H
