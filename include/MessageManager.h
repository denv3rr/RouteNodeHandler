#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include <queue>
#include <mutex>
#include <string>

// Global message queue and mutex
extern std::queue<std::string> messageQueue;
extern std::mutex messageMutex;

#endif // MESSAGE_MANAGER_H