#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <chrono>
#include "queue_stack.h"

using namespace std;

enum TraversalType_e
{
    BFS,
    DFS
};

int dice(int N)  // returns 0-(N-1)
{
    return rand() % N;
}

class Graph
{
    int N = 16; // Number of vertices
    vector<int> *out_adj;
    int* parent;
    int *level;
    bool result = true;

public:
    Graph()
    {
        out_adj = new vector<int>[N];
        level = new int[N];
        parent = new int[N];
        for(int i=0; i<N; i++){ level[i] = 0; parent[i] = -1;}
        for (int i = 0; i < 3 * N; i++)
        {
            int v = dice(N);
            int w = dice(N);
            if (find(out_adj[v].begin(), out_adj[v].end(), w) != out_adj[v].end() || w == v)
                w = dice(N);
            if (find(out_adj[v].begin(), out_adj[v].end(), w) != out_adj[v].end() || w == v)
                w = dice(N);
            if (find(out_adj[v].begin(), out_adj[v].end(), w) != out_adj[v].end() || w == v)
                w = dice(N);
            out_adj[v].push_back(w);
            // cout << endl<<  v << " " << w << endl;
        }
        cout << "Graph initialised" << endl;
    }

    void addEdge(int v, int w)
    {
        out_adj[v].push_back(w);
    }

    void Traversal(int s, TraversalType_e tt)
    {
        bool *visited = new bool[N];
        for (int i = 0; i < N; i++)
            visited[i] = false;
        Container *T;
        if (tt == 1)
            T = new Stack(); // Main Step
        else
            T = new Queue();

        visited[s] = true;
        level[s] = 0;
        T->insert(s);

        while (!T->empty())
        {
            int k = T->remove();
            cout << k << " " << level[k] << endl;
            for (int i = 0; i < out_adj[k].size(); i++)
            {
                if (!visited[out_adj[k][i]])
                {
                    parent[out_adj[k][i]] = k;
                    level[out_adj[k][i]] = level[k] + 1;
                    T->insert(out_adj[k][i]);
                    visited[out_adj[k][i]] = true;
                }
                else
                {
                    if (tt==1 && (level[out_adj[k][i]] - level[k]) % 2 == 1) result = false;
                }
            }
        }
        cout << endl;
    }
    bool isBipartite_BFS()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < out_adj[i].size(); j++)
            {
                if (level[i] == level[out_adj[i][j]] && i != out_adj[i][j] && level[i] != 0){
                    int k = i;
                    int h = out_adj[i][j];
                    while(k!=h){
                        cout << k << " " << h << endl;
                        k = parent[k];
                        h = parent[h];
                    }
                    cout << k << endl;
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite_DFS(){return result;}
};

int main()
{
    srand(time(0));
    Graph G;
    G.Traversal(0, BFS);
    G.Traversal(0,DFS);
    G.isBipartite_BFS();
//     cout << G.isBipartite_BFS() << endl;
//     cout << G.isBipartite_DFS() << endl;
}