# Graph simulator
This is a Graph Simulator. For instructions to run, scroll down.
The program graphically shows all the basic operations and uses of Graph. It first of all initialises the graph. using some number of nodes and Edges.
The Graph can do operations like BFS, DFS, Checking for Bipartite, Checking for Connectivity. All this will be done graphically.
# BFS:-
For doing this the program will call BFS_Traversal(int s), s denotes the starting node. It will follow the color changing algorithm discussed in the class. It will also list down all the nodes with there level number in the left top of the window.
# DFS:-
For doing this the program will first call DFS_initial(), This will ensure everything else is initialised. This was necessery as we are going to use a recursive algorithm for DFS. For doing DFS, the program will call DFS_Traversal(int s), s denotes the starting node. It will follow the recursive algorithm discussed in the class. It will also list down all the nodes with there level number in the left top of the window.
# Bipartite:-
This will be a great use of graphics. Here we will color the Graph, node by node. And assign each point to a particular set U and V. Basically U and V are the two partition for Bipartite Graphs. Now whenever the Graph will find an edge with endpoints of he same color. It will make a blinking animation for that particular Edge. And a result will popped in the Terminal.
# Connectivity: -
Connectivity will be checked with the help for BFS. The program will traverse the whole Graph and check for connectivity.



# How to run and use the stimulator?
First of all run the command 'make run'. This is from the makefile.
Make changes in the make file as well as the s++ file inside the simplecpp folder according to you directory structure.
Then you can just type ./a.out to run the program.
This will pop up a window, where you can give inputs from the keyboard.
Initially the screen will be blank. 
FIRSTLY!!! initialise the graph by typing i.
It will initialise the graph with 8 nodes and 15 Edges. 
# Command 'i' - Initialises the Graph
# Command 'b' - Does BFS
# Command 'd' - Does DFS
# Command 'c' - Checks for Connectivity
# Command 'p' - Checks for Bipartite property of Graph
# Command 'r' - resets the Graph to its initial state
# Command 'q' - Quits the programs
