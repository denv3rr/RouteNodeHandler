#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>
#include <thread>

// Utility functions for time calculations and printing
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start);
void printCurrentTime();
extern const std::string scroll_voodooASCII;
void coloredSeperetLogoScrolling(int, int);
void printASCIIArtScrolling(const std::string &, int, int);
void voodooASCII();
void disappointedGarfield();

#endif // FUNCTIONS_H
