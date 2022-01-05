#include <algorithm>
#include "Node.cpp"
#include "queue_stack.h"

using namespace simplecpp;

enum Graph_Type
{
    RANDOM,
    MANUAL
};

enum TraversalType
{
    BFS,
    DFS
};

class Graph : public Object
{
    int vertices;
    int number_of_Edges;
    vector<int> *Edges;
    int *parent;
    int *level;
    Node *node;
    Text *text;
    Text header;
    bool *visited = new bool[vertices];
    int j = 0;

public:
    Graph() : Object() {}
    Graph(int n, int m, Graph_Type gt) : Object()
    {
        if (gt == 0)
        {
            vertices = n;
            header = Text(40, 15, "");
            number_of_Edges = m;
            Edges = new vector<int>[n];
            level = new int[vertices];
            parent = new int[vertices];
            for (int i = 0; i < vertices; i++)
            {
                level[i] = 0;
                parent[i] = -1;
            }
            for (int i = 0; i < m; i++)
            {
                int v = dice(vertices); // dice(int n) is defined in Node.cpp, returns random number between 0 and n-1
                int w = dice(vertices);
                if (find(Edges[v].begin(), Edges[v].end(), w) != Edges[v].end() || w == v)
                    w = dice(vertices);
                if (find(Edges[v].begin(), Edges[v].end(), w) != Edges[v].end() || w == v)
                    w = dice(vertices);
                if (find(Edges[v].begin(), Edges[v].end(), w) != Edges[v].end() || w == v)
                    w = dice(vertices);
                Edges[v].push_back(w);
                Edges[w].push_back(v);
                // cout << endl<<  v << " " << w << endl;
            }
            draw_graph();
            cout << "Graph initialised Randomly" << endl;
        }
        else
        {
            vertices = n;
            header = Text(40, 15, "");
            number_of_Edges = m;
            Edges = new vector<int>[n];
            level = new int[vertices];
            parent = new int[vertices];
            for (int i = 0; i < vertices; i++)
            {
                level[i] = 0;
                parent[i] = -1;
            }
            cout << "Enter the endpoints for Edges" << endl;
            for (int i = 0; i < m; i++)
            {
                int v,w;
                cout << "Edge " << i << " - "; cin >> v >> w;
                if (find(Edges[v].begin(), Edges[v].end(), w) != Edges[v].end() || w == v){
                    cout << "The above input is invalid or already chosen." << endl;
                    i--;
                }
                Edges[v].push_back(w);
                Edges[w].push_back(v);
                // cout << endl<<  v << " " << w << endl;
            }
            draw_graph();
            cout << "Graph initialised Manually" << endl;
        }
    }
    void reset();
    void draw_graph();
    void DFS_initial();
    void DFS_Traversal(int s);
    void BFS_Traversal(int s);
    void isBipartite();
    void isConnected();
};