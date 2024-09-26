#include "../include/functions.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

// Print the execution time since start
void printExecutionTime(const std::chrono::high_resolution_clock::time_point &start)
{
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " ms" << std::endl;
}

// Print the current local time
void printCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << std::endl;
}
