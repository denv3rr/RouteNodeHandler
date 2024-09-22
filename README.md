# RouteNodeHandler
Simple handling of traffic nodes for NPCs.

## Compiling
- Current build will be compiled simply with:
    `g++ -I ./ *.cpp -o '<out file name>'`
- Or, simply:
    `g++ -I ./ *.cpp`

## Versions
- Version 1.0.0:
    - output should look like:
    >a.exe
    >Starting program...
    >Initializing nodes...
    >Initializing NPCs...
    >Simulating traffic...
    >NPC1 is at Node 1
    >NPC2 is at Node 2
    >NPC3 is at Node 1
    >NPC1 is at Node 1
    >NPC2 is at Node 2
    >(more updates)
    >Program finished.