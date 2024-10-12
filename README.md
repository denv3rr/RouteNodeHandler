<div align="center">

````

    ____              __       _   __          __     __  __                ____         
   / __ \____  __  __/ /____  / | / /___  ____/ /__  / / / /___ _____  ____/ / /__  _____
  / /_/ / __ \/ / / / __/ _ \/  |/ / __ \/ __  / _ \/ /_/ / __ `/ __ \/ __  / / _ \/ ___/
 / _, _/ /_/ / /_/ / /_/  __/ /|  / /_/ / /_/ /  __/ __  / /_/ / / / / /_/ / /  __/ /    
/_/ |_|\____/\__,_/\__/\___/_/ |_/\____/\__,_/\___/_/ /_/\__,_/_/ /_/\__,_/_/\___/_/     
                                                                                         

````



<img src="https://images.squarespace-cdn.com/content/v1/612e9679ca3ada2f6398ebb3/c05732db-3886-411e-8985-1745b6bc638a/IMG_3139-ezgif.com-crop.gif?format=1500w" alt="seperet.com spinning logo gif" width="120" height="120"/>

By Denver Clark || [Seperet](https://seperet.com)

</div>




##

- Handling of nodes for objects such as:
    - NPCs
    - Vehicles
    - and more.

- Current pathfinding algorithms in use:
    - A*
    - Dijkstra

## Supported Versions

  | Version | Supported          |
  | ------- | ------------------ |
  | > 4.3   | :white_check_mark: |
  | < 4.2   | :x:                |


## Compiling

1. Clone the repo.
    - `git clone https://github.com/denv3rr/RouteNodeHandler.git`

2. Navigate to the `src` folder.
    - `cd RouteNodeHandler/src`

3. Compile. The current build will be compiled with:
    - `g++ -I ../include *.cpp -o '<out file name>'`
    - Or, simply:
    - `g++ -I ../include *.cpp` - for a **default** out file.
    - These 2 compile options use the "Include" - `-I` tag to add the `include` folder found one directory back and all other files ending in `.cpp` (that are located in the `src` folder).
    - Depending on what you specify at compilation, the compiled out/exe file will then be added to the same folder you are in (should be `src`).

4. Run the `.exe` file.




## Issues

🚧 If you have any problems with anything, submit an issue to let me know.




## Contributing

Contributions are welcome. Please fork this repository and create a pull request with your added changes.




## Links

- seperet.com || [Seperet](https://seperet.com)
- Dijkstra, A*, and Topological Sort || [CS106B Lecture 27. Dijkstra, A*, and Topological Sort](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1242/lectures/27-graph-algorithms/)




## Notes

1. Entity Identification: Each entity (NPC or Vehicle) is identified by its type and ID, like "Entity: NPC 1" or "Entity: Vehicle 3". This clarifies which entity is being processed.

2. Start and Goal Nodes: For each entity, the start node and goal node are printed (e.g., "Start Node: 0", "Goal Node: 99"). If the start or goal node is blocked, subnodes are generated and tried.

3. Subnode Attempts: If the start or goal node is blocked, the log shows "Start node blocked, trying subnodes..." and attempts to find subnodes. The subnode IDs are also shown (e.g., "Start Node: 2899 at (0, 0, 3)").

4. Pathfinding: After attempting subnodes, the pathfinding algorithm is initiated ("Initiating pathfinding algorithm..."). If no path is found, the log prints "No path found."

5. Multithreading-like Output: The logs may seem to jump between entities because multiple entities are processed sequentially in each simulation step. This can give the appearance of multithreading but is a result of each entity attempting pathfinding one after the other. This will be added eventually.

6. Goal Reached: At the end, if a path is successfully found, it reconstructs and prints the path ("Goal node reached").




## Version History

- **Version 4.3.0:**
    - **Updates:**
        - Dynamic Subnode Grid System:
            - Implemented subnode grids that load dynamically when the main node is blocked.
            - Introduced lazy-loading subnodes between nodes, improving scalability during complex pathfinding scenarios.
        - Improved Output Format:
            - Enhanced output to display subnode creation and usage during blocked node situations, providing clearer traceability of subnodes.
        - Bug Fixes & Optimizations:
            - Refined logic for switching between nodes and subnodes during pathfinding, reducing unnecessary computations.

    - **Expected Output:**

        -   ````
            Creating nodes...
            Initializing node creation with gridSize: 5...
            Creating Node ID: 0 at (0, 0, 0)
            Adding +x neighbor to Node 0
            ...
            No path found.
            Start node blocked, trying subnodes...
            Initiating pathfinding algorithm...
            Start Node: 2799 at (0, 0, 2)
            Goal Node: 99 at (3, 4, 4)
            No path found.
            Program finished.
            Execution time: 3240 ms
            At: 2024-10-12 00:43:39

            ````

- **Version 4.2.0:**
    - **Updates:**
        - Implemented Additional Pathfinding Algorithm:
            - Introduced the DijkstraPathfinder class to provide an alternative pathfinding method alongside A*.
        - Dynamic Algorithm Selection:
            - Enabled runtime switching between A* and Dijkstra algorithms based on user input or simulation conditions.
        - Optimized Pathfinding Performance:
            - Replaced std::endl with \n in output statements to enhance compilation and execution speed.
            - Reduced overall execution time by optimizing node blocking and path recalculation logic.
        - Enhanced Node Blocking Mechanism:
            - Improved the logic for randomly blocking and unblocking nodes during simulation to reflect dynamic environments better.
        - Error Handling Enhancements:
            - Added checks to ensure the pathfinding algorithm is set before attempting to find paths, preventing runtime errors.
            - Implemented the hasAlgorithm method in PathfindingManager for safer algorithm usage.
        - Color-Coded Output for Improved Readability:
            - Enhanced console outputs with ANSI color codes to differentiate between information, warnings, and errors.
            - Ensured that node status updates (blocked/unblocked) and pathfinding results were clearly color-coded for better traceability.
        - Bug Fixes:
            - Resolved issues related to undefined functions and missing includes, ensuring smoother compilation and runtime stability.

    - **(Working On):**
        - Foundation for Dynamic Subnode Grids:
            - Build groundwork for implementing dynamic subnode grids that load on-demand during specific scenarios like blockages, enhancing the simulation's scalability for more complex issues.
        - Code Refactoring for Modularity and Test-Driven Development (TDD):
            - Refactor existing code to support future expansions and facilitate easier testing.
            - Structure classes and methods to promote modularity (to make the codebase more maintainable).
        - Advanced Traffic Rules Implementation:
            - Introduce more sophisticated traffic rules, including stoplights, speed limits, and intersection management, to increase simulation realism.
        - Entity Behavior Models:
            - Implement diverse behaviors for entities (NPCs and vehicles), such as aggressive, cautious, or normal driving styles, to enrich the simulation dynamics.
        - Additional Pathfinding Algorithms:
            - Expand the pathfinding toolkit by adding more algorithms like Best-First Search or Bidirectional Search for comparative analysis and enhanced flexibility.

- **Version 4.1.0:**
    - **Updates:**
        - Modularized pathfinding logic by introducing the AStarPathfinder class.
        - Added detailed debugging statements with color-coded outputs for better traceability.
        - Improved gScore initialization and handling in the A* algorithm to fix pathfinding issues.

    - **Expected Output:**

        -   ````
            Starting program...

            Creating nodes...
            Initializing node creation with gridSize: 20...
            Creating Node ID: 0 at (0, 0, 0)
            Creating Node ID: 1 at (0, 0, 1)
            Creating Node ID: 2 at (0, 0, 2)
            ...
            (***MORE UPDATES***)
            ...
            Adding +x neighbor to Node 2865, Neighbor Index: 3265
            ...
            (***MORE UPDATES***)
            ...
            Finding path from Node 0 to Node 99...
            Initiating pathfinding algorithm...
            Processing Node: 0
            Evaluating Neighbor: 400 with tentative gScore: 1
            Neighbor: 400 not added, worse gScore.
            ...
            No path found.

            Path from Node 0 to Node 99:

            *************************

            Program finished.
            Execution time: 17346 ms
            At: 2024-09-27 01:41:16

            ````

- **Version 4.0.0:**
    - **Updates:**
        - Added more robust debugging statements
        - Previous pathfinding issues persisted due to incorrect `gScore` handling.

    - **Expected Output:**

        -   ````
            Starting program...

            Creating nodes...
            Initializing node creation with gridSize: 20...
            Creating Node ID: 0 at (0, 0, 0)
            Creating Node ID: 1 at (0, 0, 1)
            Creating Node ID: 2 at (0, 0, 2)
            Creating Node ID: 3 at (0, 0, 3)
            Creating Node ID: 4 at (0, 0, 4)
            Creating Node ID: 5 at (0, 0, 5)
            ...
            ...
            (***MORE UPDATES***)
            ...
            ...
            Adding +x neighbor to Node 2865, Neighbor Index: 3265
            Adding -y neighbor to Node 2865, Neighbor Index: 2845
            Adding +y neighbor to Node 2865, Neighbor Index: 2885
            Adding -z neighbor to Node 2865, Neighbor Index: 2864
            Adding +z neighbor to Node 2865, Neighbor Index: 2866
            Adding -x neighbor to Node 2866, Neighbor Index: 2466

            ...
            ...
            (***MORE UPDATES***)
            ...
            ...
            Finding path from Node 0 to Node 99...
            Initiating pathfinding algorithm...
            Processing Node: 0
            Evaluating Neighbor: 400 with tentative gScore: 1
            Neighbor: 400 not added, worse gScore.
            Evaluating Neighbor: 20 with tentative gScore: 1
            Neighbor: 20 not added, worse gScore.
            Evaluating Neighbor: 1 with tentative gScore: 1
            Neighbor: 1 not added, worse gScore.
            No path found.

            Path from Node 0 to Node 99:

            *************************

            Program finished.
            Execution time: 17346 ms
            At: 2024-09-27 01:41:16
            ````

- **Version 3.1.0:**
    - **Updates:**

    - **Expected Output:**

        -   ````
            Starting program...

            Initialized 8000 nodes in a 20x20x20 grid.

            Node ID: 0 at (0, 0, 0)
            Node ID: 1 at (0, 0, 1)
            Node ID: 2 at (0, 0, 2)
            Node ID: 3 at (0, 0, 3)
            Node ID: 4 at (0, 0, 4)
            Node ID: 5 at (0, 0, 5)
            ...
            ...
            (***MORE UPDATES***)
            ...
            ...
            Node ID: 7995 at (19, 19, 15)
            Node ID: 7996 at (19, 19, 16)
            Node ID: 7997 at (19, 19, 17)
            Node ID: 7998 at (19, 19, 18)
            Node ID: 7999 at (19, 19, 19)

            Simulating traffic...

            Initiating pathfinding algorithm...
            Processing Node: 0
            No path found.
            ...
            ...
            (***MORE UPDATES***)
            ...
            ...

            Path from Node 0 to Node 99:

            *************************

            Program finished.
            Execution time: 2298 ms
            At: 2024-09-27 00:46:18

            ````

- **Version 3.0.0:**
    - **Updates:**
        - Slowly implementing dynamic node creation functionality.

    - **Expected Output:**

        -   ````
            Starting program...
            Node ID: 1 at (0, 0, 0)
            Node ID: 2 at (0, 0, 1)
            Node ID: 3 at (0, 0, 2)
            Node ID: 4 at (0, 0, 3)
            Node ID: 5 at (0, 0, 4)
            ...
            ...
            (***MORE UPDATES***)
            ...
            ...
            Node ID: 7996 at (19, 19, 15)
            Node ID: 7997 at (19, 19, 16)
            Node ID: 7998 at (19, 19, 17)
            Node ID: 7999 at (19, 19, 18)
            Node ID: 8000 at (19, 19, 19)
            Simulating traffic...

            Vehicle 699924208 moved to Node ID:

            ````

- **Version 2.0.0:**
    - **Updates:**

    - **Expected Output**:

        -   ````
        
            Starting program...
            Initializing nodes...
            Initializing NPCs...
            Initializing Vehicles...
            Simulating traffic...


            NPC 1 is at Node 1
            NPC 2 is at Node 2
            NPC 3 is at Node 1
            Vehicle 1 is at Node 1
            Vehicle 2 is at Node 2
            Vehicle 3 is at Node 1
            ...
            ...
            (***MORE UPDATES***)
            ...
            ...
            NPC 1 is at Node 1
            NPC 2 is at Node 2
            NPC 3 is at Node 1
            Vehicle 1 is at Node 1
            Vehicle 2 is at Node 2
            Vehicle 3 is at Node 1

            *************************

            Program finished.
            Execution time: 0.0164633 seconds
            At Current time: Wed Sep 25 20:54:28 2024

            ````

- **Version 1.0.0:**
    - **Updates:**

    - **Expected Output:**

        -   ````
            Starting program...
            Initializing nodes...
            Initializing NPCs...
            Simulating traffic...
            NPC1 is at Node 1
            NPC2 is at Node 2
            NPC3 is at Node 1
            NPC1 is at Node 1
            NPC2 is at Node 2
            ...
            ...
            (***MORE UPDATES***)
            ...
            ...
            Program finished.
            ````




##

<div align="center">
<img src="https://images.squarespace-cdn.com/content/v1/612e9679ca3ada2f6398ebb3/5c5d2752-5b10-4535-9591-acff011443fa/3dgifmaker21328.gif?format=1500w" width="300" height="300"/>

[Seperet](https://seperet.com)
</div>
