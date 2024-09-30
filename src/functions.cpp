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

// Function to print the logo with specified colors
void coloredSeperetLogo(int colorCode1, int colorCode2)
{
    // Print the first part of the logo with colorCode1
    std::cout << "\033[" << colorCode1 << "m"; // Start color 1
    std::cout << R"(
 __   ____  ___   ____  ___   ____ _____ 
( (` | |_  | |_) | |_  | |_) | |_   | |  )";
    std::cout << "\033[0m"; // End color 1

    // Print the second part of the logo with colorCode2
    std::cout << "\n\033[" << colorCode2 << "m"; // Start color 2
    std::cout << R"(_)_) |_|__ |_|   |_|__ |_| \ |_|__  |_|  

)";
    std::cout << "\033[0m"; // End color 2
}

void voodooASCII()
{
    std::cout << R"(
    
                                @@@%@%@@@                       
                               @@@=----+%@@                     
                              @*:%*------+@@                    
                             @=...%+------+@@                   
                          @@@+.....@@+----=@@                   
                          @@@@=#=@:.%%%====*@@                  
                          @%:..%@@...+-.=%@@@                   
                          @-.....@..*@%*.*@@                    
                         @+..+@...::::==@@@                     
                         @@-.-@%=.:=*=@@@@@                     
                         @@@@:#@@@@@@@@                         
                    @@@@*==@@@@@@@@@@@@                         
                   @@%@@=--*@#@@@#@@@@@@@                       
                  @@#+*%=--=--@@%%#%@@@@@@                      
                  @#++#%=----=@%#@%%%@@@@@@                     
                 @@+++%#------@######@@@@@@@                    
                @@++++%#----+*@%%####@@@@@@@@                   
                @*+++*%%--+@@*+==@%##%@@@@@@@@                  
               @@+++=+%@=*@**=====@%##@@@@@@@@@                 
              @@@@@#**%@%%*++======@%#@@@@@@@@@                 
               @@@%%%@@%%%+=+===--=@@#%@@@@@@@                  
                 @@@@@@=*@#+======-#@#%@@@@     @@@@@@@@@@@@@@  
                 @@@*=#=-@@%+==-==%@#%%%@@@@@@@@%%%%%%%%%%%**@@ 
               @@@%%%@@#+==*@@@@@%##@@%%%%%%%%%%%%%%%%%%%%%=%@@ 
             @@%%%%%%%%@%*+--=*@###@%%%%%%%%%%%%%%%%%%%%%@*-#@@ 
          @@%%%%%%%%%%%@@@%+*#%@%@@@@@@@%%%%%%%%%%%%%%%%@@+=@@  
       @@%%%%%%%%%%%%%@@             @@@@@@@@@%%%@%%%%%%--%@@  
    @@@%%%%%%%%%%%%%@@@                     @@@@@@@@@%@@@%@@@   
  @@%%%%%%%%%%%%%%%@@@                             @@@@@@@@@    
  @*=#@@%%%%%%%%%%@@                                            
  @*...:=@%%%%%%%@@                                             
  @@:.....:@%%%@@@                                              
   @@=....:*@%@@                                                
    @@#+===#@@@                                                 
      @@@@@@@         seperet.com || Denver Clark                                               




)";
}

void disappointedGarfield()
{
    // Makes you feel pretty guilty
    std::cout << R"(

    Garfield                       ...ooooo.         ..---##o
                          .--^""#########o ..o--"  .o#####
        .."-.         ..-^"  .o###########^"    .o########
      ..."^o ^.    .o^"    o##^"#"#"#"#"##   .o#^:^:^:^:#
        "^-:^.# .o#:-    o^"    "-"-"-"-##.o^"-^" " " :# .-^""
           ::#"##o#^.  -""..---------...":^-------. o#^.^.#:"
         -:.-:^:"oo^   .-"             ""o         ^:^#:#"
     ..o:^o:#o:##""  o"                  "o          # "-o.
    o"." ^"-"^-""   #                     #           #  .#.
  .^o"o:-. .        #                    .^           #o-#-#
 .#^.^.^#^#^        #                ...o:      .....o""o^o"#
 #^ "-"- "           #""""^####^""""".-"#####^""""  o"  ^.^.^o
 "#"o"o       .#--""" ^..       ..oo###oo.      ..-"    o:o"o^
  ^-o:o".   .^"          """""""  ::^^^^^::"""""        ^.#-#
    "^o:-:-#   -        ..    .o-"         "--..    .    ^.^
      "-:-:^o            """"""                 """"     o"
         "^-^#.   .o^#...........................    ..-"
              """""   ""                         """")";
}