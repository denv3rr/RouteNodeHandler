#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>

// Utility functions for time calculations and printing
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start);
void printCurrentTime();

#endif // FUNCTIONS_H
