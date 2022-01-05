#include <simplecpp>
#include "Graph.cpp"

using namespace simplecpp;

main_program
{
    srand(5);
    bool Exit = false;  // Will be used for Quitting the program
    initCanvas("Graph", WINDOW_X, WINDOW_Y);  // Initialising the Graph window
    Graph* G;
    string msg("Cmd: _");   // Command key
    Text charPressed(PLAY_X_START + 50, PLAY_Y_HEIGHT + 20, msg);
    for (;;)
    {
        if (Exit)
            exit(0);
        XEvent e;
        bool pendingEv = checkEvent(e);
        if (pendingEv)
        {
            char c = charFromEvent(e);    // Takes the char input
            msg[msg.length() - 1] = c;
            charPressed.setMessage(msg);
            switch (c)
            {
            case 'i':
            {
                int type = 0;
                int n = 8, m = 15;
                G = new Graph(n,m,type? MANUAL:RANDOM);   // Initialising the Graph
                break;
            }
            case 'b':
                G->BFS_Traversal(0);    // Does BFS staring from node 0
                break;
            case 'd':
                G->DFS_initial();   // Initiliasing some stuffs before doing DFS
                // The above step is necessary as the DFS_Traversal is recursive
                G->DFS_Traversal(3);
                break;
            case 'r':
                G->reset();
                break;
            case 'p':
                cout << "Checking for the Bipartite property of the Graph" << endl;
                G->isBipartite();  // Will also output the result in the terminal
                break;
            case 'c':
                cout << "Checking for connectivity of the Graph" << endl;
                G->isConnected();  // Will also output the result in the terminal
                break;
            case 'q':
                Exit = true; // Exits the graph
            default:
                break;
            }
        }
    }
}