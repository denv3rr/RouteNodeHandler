# RouteNodeHandler

- Simple handling of nodes for objects such as:
    - NPCs
    - Vehicles
    - and more.

## Compiling
- Current build will be compiled simply with:
    `g++ -I ../include *.cpp -o '<out file name>'`
- Or, simply:
    `g++ -I ../include *.cpp`

- These 2 compile options uses the "Include" tag to include the `include` folder as well as all files ending in `.cpp`.

- The compiled out/exe file will then be added into the same folder (`src`) depending on what you specify at compilation.

## Versions

- Version 2.0.0:
    - output should look like:

    ````
    
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

    ````
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
