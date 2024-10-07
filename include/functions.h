#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>
#include <thread>

// Utility functions for time calculations and printing
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start);
void printCurrentTime();
void coloredSeperetLogoScrolling(int, int);
void coloredLogoScrolling(int, int, int, int);
void printASCIIArtScrolling(const std::string &, int, int);

#endif // FUNCTIONS_H
