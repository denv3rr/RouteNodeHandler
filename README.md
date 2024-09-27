# RouteNodeHandler

- Simple handling of nodes for objects such as:
    - NPCs
    - Vehicles
    - and more.

## Compiling

- Navigate to the `src` folder.

- Current build will be compiled with:
    - `g++ -I ../include *.cpp -o '<out file name>'`
- Or, simply:
    - `g++ -I ../include *.cpp` - for a default out file.

- These 2 compile options use the "Include" tag to add the `include` folder as well as all files ending in `.cpp`.

- The compiled out/exe file will then be added into the same folder you are in (`src`) - depending on what you specify at compilation.

## Versions

- Version 3.1.0:
    - output should look like:

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

- Version 3.0.0:
    - Slowly implementing dynamic node creation functionality.
    - output should look like:

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

- Version 2.0.0:
    - output should look like:

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

- Version 1.0.0:
    - output should look like:

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
