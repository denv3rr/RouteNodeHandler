#include "AStarPathfinder.h"

extern std::mutex consoleMutex; // Use the same mutex defined globally for output

std::vector<Node *> AStarPathfinder::findPath(std::shared_ptr<Node> startNode, std::shared_ptr<Node> goalNode)
{
    {
        std::lock_guard<std::mutex> lock(consoleMutex); // Lock console output
        // std::cout << "\033[32mInitiating pathfinding algorithm...\033[0m\n";
        // std::cout << "\033[32mStart Node: \033[0m" << startNode->getId() << " at (" << startNode->getX() << ", " << startNode->getY() << ", " << startNode->getZ() << ")\n";
        // std::cout << "\033[32mGoal Node: \033[0m" << goalNode->getId() << " at (" << goalNode->getX() << ", " << goalNode->getY() << ", " << goalNode->getZ() << ")\n";
    }

    std::priority_queue<
        std::pair<float, std::shared_ptr<Node>>,
        std::vector<std::pair<float, std::shared_ptr<Node>>>,
        std::greater<std::pair<float, std::shared_ptr<Node>>>>
        openSet;

    openSet.emplace(0.0f, startNode);

    std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> cameFrom;
    std::unordered_map<std::shared_ptr<Node>, float> gScore;
    std::unordered_map<std::shared_ptr<Node>, float> fScore;

    gScore[startNode] = 0.0f;
    fScore[startNode] = heuristicCostEstimate(startNode, goalNode);

    while (!openSet.empty())
    {
        std::shared_ptr<Node> current = openSet.top().second;
        openSet.pop();

        if (current == goalNode)
        {
            {
                std::lock_guard<std::mutex> lock(consoleMutex); // Lock console output
                // std::cout << "\n\n\033[32mGoal node reached.\033[0m\n\nReconstructing path...\n\n";
            }
            return reconstructPath(cameFrom, current);
        }

        for (const auto &neighbor : current->getNeighbors())
        {
            if (!neighbor)
            {
                {
                    std::lock_guard<std::mutex> lock(consoleMutex); // Lock console output
                    // std::cout << "\033[31mInvalid neighbor for Node: \033[0m" << current->getId() << "\n";
                }
                continue;
            }

            float tentative_gScore = gScore[current] + distance(current, neighbor);

            if (gScore.find(neighbor) == gScore.end())
            {
                gScore[neighbor] = std::numeric_limits<float>::infinity();
            }

            if (tentative_gScore < gScore[neighbor])
            {
                cameFrom[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + heuristicCostEstimate(neighbor, goalNode);
                openSet.emplace(fScore[neighbor], neighbor);
            }
        }
    }

    {
        std::lock_guard<std::mutex> lock(consoleMutex); // Lock console output
        // std::cout << "\n\033[31mNo path found.\033[0m\n";
    }
    return std::vector<Node *>();
}

float AStarPathfinder::heuristicCostEstimate(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
{
    return std::sqrt(std::pow(goal->getX() - start->getX(), 2) +
                     std::pow(goal->getY() - start->getY(), 2) +
                     std::pow(goal->getZ() - start->getZ(), 2));
}

float AStarPathfinder::distance(const std::shared_ptr<Node> &start, const std::shared_ptr<Node> &goal) const
{
    return heuristicCostEstimate(start, goal);
}

std::vector<Node *> AStarPathfinder::reconstructPath(std::unordered_map<std::shared_ptr<Node>, std::shared_ptr<Node>> &cameFrom, std::shared_ptr<Node> current)
{
    std::vector<Node *> path;
    while (cameFrom.find(current) != cameFrom.end())
    {
        path.push_back(current.get());
        current = cameFrom[current];
    }
    path.push_back(current.get());
    std::reverse(path.begin(), path.end());
    return path;
}
