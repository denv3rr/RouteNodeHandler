/* *************************************************
 * functions.h
 * Purpose: functions.cpp header file
 ************************************************* */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Standard
#include <chrono>
#include <ctime>
#include <iostream>

// Local
// --

// Prototypes:

void printCurrentTime();

// Uses chrono library to get runtime clock for debugging
void printExecutionTime(std::chrono::time_point<std::chrono::high_resolution_clock> start);

#endif // FUNCTIONS_H