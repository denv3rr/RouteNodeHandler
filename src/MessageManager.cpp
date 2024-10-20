#include "MessageManager.h"

// Define the global message queue and mutex
std::queue<std::string> messageQueue;
std::mutex messageMutex;