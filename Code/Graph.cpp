#include "Graph.h"

void Graph::reset()     // Resets the graph into it initial state
{
    header.setMessage("");
    for (int i = 0; i < vertices; i++)
    {
        node[i].changeColor(COLOR("yellow"));
        node[i].setFill(true);
        text[i].setMessage("");
    }
}

void Graph::draw_graph()       // Draws the graph with the given number of vertices and edges
{
    text = new Text[vertices];
    node = new Node[vertices];
    for (int i = 0; i < vertices; i++)
    {
        node[i] = Node(i);
        text[i] = Text(35, 45 + 25 * i, "");
    }
    for (int i = 0; i < vertices; i++)
    {
        for (unsigned int j = 0; j < Edges[i].size(); j++)
        {
            int x1 = node[i].getX(); // coordinates for node 1;
            int y1 = node[i].getY();
            int x2 = node[Edges[i][j]].getX();
            int y2 = node[Edges[i][j]].getY();
            Line Edge(x1, y1, x2, y2);
            Edge.imprint();
        }
        // wait(10);
        node[i].setFill(true);
    }
}

void Graph::DFS_initial()   // Initialises some stuffs before doing DFS
{
    header.setMessage("node level ");
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        level[i] = 0;
        text[i].setMessage("");
        node[i].changeColor(COLOR("yellow"));
    }
}

void Graph::DFS_Traversal(int s)   // Traverses the Graph using Depth First Search
{
    // Mark the current node as visited and
    // print it
    visited[s] = true;
    wait(1);
    node[s].changeColor(COLOR("green"));
    text[j].setMessage(to_string(s) + "   " + to_string(level[s]));
    wait(1);
    j++;
    // Recur for all the vertices adjacent
    // to this vertex
    for (unsigned int i = 0; i < Edges[s].size(); ++i)
    {
        if (!visited[Edges[s][i]])
        {
            parent[Edges[s][i]] = s;
            level[Edges[s][i]] = level[s] + 1;
            wait(2);
            visited[Edges[s][i]] = true;
            DFS_Traversal(Edges[s][i]);
        }
    }
    wait(1);
    node[s].changeColor(COLOR("yellow"));
}

void Graph::BFS_Traversal(int s)       // Traverses the Graph using BFE algorithm
{
    header.setMessage("node level ");
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        text[i].setMessage("");
        node[i].changeColor(COLOR("white"));
    }
    Container *T = new Queue();

    visited[s] = true;
    level[s] = 0;
    wait(1);
    node[s].changeColor(COLOR("green"));
    T->insert(s);
    wait(1);
    text[0].setMessage(to_string(s) + "   " + to_string(level[s]));
    wait(1);
    int j = 1;
    while (!T->empty())
    {
        int k = T->remove();
        // cout << k << " " << level[k] << endl;
        node[k].changeColor(COLOR("yellow"));
        wait(1.5);
        for (unsigned int i = 0; i < Edges[k].size(); i++)
        {
            if (!visited[Edges[k][i]])
            {
                node[Edges[k][i]].changeColor(COLOR("green"));
                parent[Edges[k][i]] = k;
                level[Edges[k][i]] = level[k] + 1;
                text[j].setMessage(to_string(Edges[k][i]) + "   " + to_string(level[Edges[k][i]]));
                wait(1);
                T->insert(Edges[k][i]);
                visited[Edges[k][i]] = true;
                j++;
            }
        }
        wait(2);
    }
    // cout << endl;
}

void Graph::isBipartite()
{
    bool result = true;
    header.setMessage("node  set");
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        text[i].setMessage("");
        node[i].changeColor(COLOR("white"));
    }
    Container *T = new Queue();
    int s = 0;
    visited[s] = true;
    level[s] = 0;
    T->insert(s);
    wait(1);
    node[0].changeColor(COLOR("yellow"));
    node[0].color = 2;
    text[0].setMessage(to_string(s) + "   U");
    wait(1);
    int j = 1;
    while (!T->empty())
    {
        if (!result)
            break;
        int k = T->remove();
        // cout << k << " " << level[k] << endl;
        for (unsigned int i = 0; i < Edges[k].size(); i++)
        {
            if (!visited[Edges[k][i]])
            {
                if (node[k].color == 2)
                {
                    node[Edges[k][i]].changeColor(COLOR("green"));
                    node[Edges[k][i]].color = 1;
                    text[j].setMessage(to_string(Edges[k][i]) + "   V");
                }
                else if (node[k].color == 1)
                {
                    node[Edges[k][i]].changeColor(COLOR("yellow"));
                    node[Edges[k][i]].color = 2;
                    text[j].setMessage(to_string(Edges[k][i]) + "   U");
                }
                parent[Edges[k][i]] = k;
                level[Edges[k][i]] = level[k] + 1;
                wait(1);
                T->insert(Edges[k][i]);
                visited[Edges[k][i]] = true;
                j++;
            }
            else
            {
                if (node[k].color == node[Edges[k][i]].color)
                {
                    result = false;
                    int x1 = node[i].getX(); // coordinates for node 1;
                    int y1 = node[i].getY();
                    int x2 = node[Edges[k][i]].getX();
                    int y2 = node[Edges[k][i]].getY();
                    Line Edge(x1, y1, x2, y2);
                    // Edge.setThickness(5);


                    // This is just a code which blinks the edge which fails Bipartite case
                    node[k].setFill(true);
                    node[Edges[k][i]].setFill(true);
                    wait(0.4);
                    Edge.setThickness(2);
                    node[k].setFill(true);
                    node[Edges[k][i]].setFill(true);
                    wait(0.4);
                    Edge.setThickness(5);
                    node[k].setFill(true);
                    node[Edges[k][i]].setFill(true);
                    wait(0.4);
                    Edge.setThickness(2);
                    node[k].setFill(true);
                    node[Edges[k][i]].setFill(true);
                    wait(0.4);
                    Edge.setThickness(5);
                    node[k].setFill(true);
                    node[Edges[k][i]].setFill(true);
                    wait(1);
                    break;
                }
            }
        }
    }
    cout << (result? "The Graph is Bipartite" : "The Graph is not Bipartite") << endl;
    wait(2);
}

void Graph::isConnected(){     // Checks for connectivity 
    int s = dice(vertices);
    BFS_Traversal(s);
    for(int i=0; i<vertices; i++){
        if(!visited[i]) {
            cout << "Not connected for " << s << " and " << i << endl;
            return;
        }
    }
    cout << "Graph is Connected" << endl;
}
