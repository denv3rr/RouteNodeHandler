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
  std::cout << "Execution time: " << duration << " ms (" << duration / 1000 << " sec)" << std::endl;
}

// Print the current local time
void printCurrentTime()
{
  auto now = std::chrono::system_clock::now();
  std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::cout << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << std::endl;
}

// Function to print the logo with specified colors and scrolling effect
void coloredSeperetLogoScrolling(int colorCode1, int colorCode2)
{
  // First part of the logo
  std::string logoPart1 = R"(
                __   ____  ___   ____  ___   ____ _____ 
               ( (` | |_  | |_) | |_  | |_) | |_   | |  )";

  // Second part of the logo
  std::string logoPart2 = R"(               _)_) |_|__ |_|   |_|__ |_| \ |_|__  |_|  
    
)";

  // Set color for first part
  std::cout << "\033[" << colorCode1 << "m"; // Start color 1

  // Print first part character by character
  for (char c : logoPart1)
  {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Adjust delay as needed
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
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Adjust delay as needed
  }

  // Reset color
  std::cout << "\033[0m"; // End color 2
}

// Function to print the logo with specified colors and scrolling effect
void coloredLogoScrolling(int colorCode1, int colorCode2, int colorCode3, int colorCode4)
{
  // Logo parts
  std::string logoPart1 = R"(
          ____              __          _   __          __   
         / __ \____  __  __/ /____     / | / /___  ____/ /__ 
        / /_/ / __ \/ / / / __/ _ \   /  |/ / __ \/ __  / _ \)";

  std::string logoPart2 = R"(
       / _, _/ /_/ / /_/ / /_/  __/  / /|  / /_/ / /_/ /  __/
      /_/ |_|\____/\__,_/\__/\___/__/_/ |_/\____/\__,_/\___/)";

  std::string logoPart3 = R"(
                / / / /___ _____  ____/ / /__  _____              
               / /_/ / __ `/ __ \/ __  / / _ \/ ___/)";

  std::string logoPart4 = R"(              
              / __  / /_/ / / / / /_/ / /  __/ /                  
             /_/ /_/\__,_/_/ /_/\__,_/_/\___/_/)";

  // Helper lambda to print a logo part with color and optional delay
  auto printLogoPart = [](const std::string &part, int colorCode, int delayPerChar)
  {
    // Set color
    std::cout << "\033[" << colorCode << "m";

    // Print part character by character
    for (char c : part)
    {
      std::cout << c << std::flush;
      // Optional delay after non-whitespace characters
      if (!std::isspace(static_cast<unsigned char>(c)) && delayPerChar > 0)
      {
        std::this_thread::sleep_for(std::chrono::milliseconds(delayPerChar));
      }
    }

    // Reset color
    std::cout << "\033[0m";
  };

  // Adjust delayPerChar as needed (set to 0 for no delay)
  int delayPerChar = 1; // Set to 0 for no delays in scroll animation

  // Print each part
  printLogoPart(logoPart1, colorCode1, delayPerChar);

  printLogoPart(logoPart2, colorCode2, delayPerChar);
  std::cout << "\n";

  printLogoPart(logoPart3, colorCode3, delayPerChar);

  printLogoPart(logoPart4, colorCode4, delayPerChar);
}

// Function to print ASCII art with scrolling effect, skipping whitespace delays
void printASCIIArtScrolling(const std::string &asciiArt, int delayNonWhitespace, int delayLine)
{
  for (size_t i = 0; i < asciiArt.size(); ++i)
  {
    char c = asciiArt[i];
    std::cout << c << std::flush;

    // Skip delay for whitespace characters
    if (!std::isspace(static_cast<unsigned char>(c)))
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(delayNonWhitespace));
    }

    // Optional: Add a longer delay at the end of each line
    if (c == '\n')
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(delayLine));
    }
  }
}
