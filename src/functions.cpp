/* *************************************************
 * functions.cpp
 * Purpose: Stores program functions
 ************************************************* */
#include "functions.h"
#include <iostream>
#include <ctime>
#include <chrono>

void printCurrentTime()
{
    std::time_t now = std::time(nullptr);
    std::cout << "Current time: " << std::ctime(&now);
}

void printExecutionTime(std::chrono::time_point<std::chrono::high_resolution_clock> start)
{
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
}