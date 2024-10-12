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
