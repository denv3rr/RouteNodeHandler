#include "../include/TrafficManager.h"

void TrafficManager::addNPC(NPC *npc)
{
    npcs.push_back(npc);
}

void TrafficManager::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

// Sets a reference to NodeManager for managing nodes during traffic simulation
void TrafficManager::setNodeManager(NodeManager *nodeManager)
{
    this->nodeManager = nodeManager;
}

// Updated Traffic Manager logic to handle node creation
void TrafficManager::updateTraffic()
{
    for (auto &npc : npcs)
    {
        Node *currentNode = npc->getCurrentNode();
        const auto &neighbors = currentNode->getNeighbors();

        // If no neighbors exist, add a dynamic node nearby
        if (neighbors.empty() && nodeManager)
        {
            Node *newNode = nodeManager->addDynamicNode(currentNode->getX() + 2.0f, currentNode->getY() + 2.0f);
            npc->moveToNode(newNode);
            std::cout << "NPC moved to newly created Node ID: " << newNode->getId() << "\n";
        }
        else if (!neighbors.empty())
        {
            Node *nextNode = neighbors[rand() % neighbors.size()];
            npc->moveToNode(nextNode);
            std::cout << "NPC moved to Node ID: " << nextNode->getId();
            std::cout << " at (" << nextNode->getX() << ", " << nextNode->getY() << ", " << nextNode->getZ() << ")\n";
        }
    }

    for (auto &vehicle : vehicles)
    {
        Node *currentNode = vehicle->getCurrentNode();
        const auto &neighbors = currentNode->getNeighbors();

        // Similar dynamic node creation logic for vehicles
        if (neighbors.empty() && nodeManager)
        {
            Node *newNode = nodeManager->addDynamicNode(currentNode->getX() + 3.0f, currentNode->getY() + 3.0f);
            vehicle->moveToNode(newNode);
            std::cout << "Vehicle moved to newly created Node ID: " << newNode->getId() << "\n";
        }
        else if (!neighbors.empty())
        {
            Node *nextNode = neighbors[rand() % neighbors.size()];
            vehicle->moveToNode(nextNode);
            std::cout << "Vehicle moved to Node ID: " << nextNode->getId();
            std::cout << " at (" << nextNode->getX() << ", " << nextNode->getY() << ", " << nextNode->getZ() << ")\n";
        }
    }
}
