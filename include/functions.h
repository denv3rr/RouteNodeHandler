#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>

// Utility functions for time calculations and printing
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start);
void printCurrentTime();
void coloredSeperetLogo(int colorCode1, int colorCode2);

#endif // FUNCTIONS_H
