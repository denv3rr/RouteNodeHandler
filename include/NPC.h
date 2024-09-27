#ifndef NPC_H
#define NPC_H

#include "Entity.h"
#include <vector>

class NPC : public Entity
{
public:
    NPC(int id, Node *startNode);
    int getId() const;
    Node *getCurrentNode() const;

    // Add this method to allow setting a path
    void setPath(const std::vector<Node *> &newPath);

    void move() override;

private:
    std::vector<Node *> path; // Store the NPC's path
};

#endif // NPC_H
