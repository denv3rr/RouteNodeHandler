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

-  Keep track of entity data (3D) while they search for a location.
    -  Currently supporting entities such as:
        - NPCs
        - Vehicles
        - and more - feel free to add your own.

    - Current pathfinding algorithms in use:
        - A*
        - Dijkstra



##
<div align="center">
    <img src="https://i.imgur.com/vC71luv.gif" width="200" height="200"/>
    <div>
        Example of the A* algorithm in use in a Python program.
    </div>
</div>



        
## Supported Versions

  | Version | Supported          |
  | ------- | ------------------ |
  | > 4.3   | :white_check_mark: |
  | < 4.2   | :x:                |

(See `versions.md` for version history.)




## Compiling

1. Clone the repo.
    - `git clone https://github.com/denv3rr/RouteNodeHandler.git`

2. Navigate to the `src` folder.
    - `cd RouteNodeHandler/src`

3. Compile. The current build can be compiled with 2 options:
    1. Named:
        - `g++ -I ../include *.cpp -o '<out file name>'`
    2. Default:
        - `g++ -I ../include *.cpp` - for an **unnamed** out file.
    
    - These 2 compile options use the "Include" (`-I`) tag to add 2 things:
        1. The `include` folder found one directory back: `../include`
        2. All (`*`) other files ending in `.cpp` (located in the `src` folder).

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




##

<div align="center">
<img src="https://images.squarespace-cdn.com/content/v1/612e9679ca3ada2f6398ebb3/5c5d2752-5b10-4535-9591-acff011443fa/3dgifmaker21328.gif?format=1500w" width="300" height="300"/>

[Seperet](https://seperet.com)
</div>
