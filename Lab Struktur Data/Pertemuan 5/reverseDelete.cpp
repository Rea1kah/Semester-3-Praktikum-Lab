#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> iPair;

class Graph
{
    int V;
    list<int> *adj;
    vector<pair<int, iPair>> edges;
    void DFS(int v, vector<bool> &visited);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int u, int v, int w);
    bool isConnected();
    void reverseDeleteMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.push_back({w, {u, v}});
}

void Graph::DFS(int v, vector<bool> &visited)
{
    visited[v] = true;
    for (int neighbor : adj[v])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, visited);
        }
    }
}

bool Graph::isConnected()
{
    if (V == 0)
    {
        return true;
    }

    vector<bool> visited(V, false);
    DFS(0, visited);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }

    return true;
}

void Graph::reverseDeleteMST()
{
    sort(edges.begin(), edges.end());

    int mst_wt = 0;

    cout << "Edges in MST\n";

    for (int i = edges.size() - 1; i >= 0; i--)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        adj[u].remove(v);
        adj[v].remove(u);

        if (isConnected() == false)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);

            cout << "(" << u << ", " << v << ") \n";
            mst_wt += edges[i].first;
        }
    }

    cout << "Total weight of MST is " << mst_wt << endl;
}

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.reverseDeleteMST();
    return 0;
}