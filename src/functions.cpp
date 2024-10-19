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
  std::cout << "Execution time: " << duration << " ms (" << duration / 1000 << " sec)\n";
}

// Print the current local time
void printCurrentTime()
{
  auto now = std::chrono::system_clock::now();
  std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::cout << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S\n");
}

// Function to print the logo with specified colors and scrolling effect
void coloredSeperetLogoScrolling(int colorCode1, int colorCode2)
{
  // First part of the logo
  std::string logoPart1 = R"(
 __   ____  ___   ____  ___   ____ _____ 
( (` | |_  | |_) | |_  | |_) | |_   | |  )";

  // Second part of the logo
  std::string logoPart2 = R"(_)_) |_|__ |_|   |_|__ |_| \ |_|__  |_|  
    
)";

  // Set color for first part
  std::cout << "\033[" << colorCode1 << "m"; // Start color 1

  // Print first part character by character
  for (char c : logoPart1)
  {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(0)); // Adjust delay as needed
  }

  // Reset color
  std::cout << "\033[0m"; // End color 1

  // Newline before second part
  std::cout << "\n";

  // Set color for second part
  std::cout << "\033[" << colorCode2 << "m"; // Start color 2

  // Print second part character by character
  for (char c : logoPart2)
  {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(0)); // Adjust delay as needed
  }

  // Reset color
  std::cout << "\033[0m"; // End color 2
}