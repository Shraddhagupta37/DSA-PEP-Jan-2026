/*
A graph G = (V,E) consists of:
    V -> A set of vertices (nodes), which are individual objects in the graph
    E -> A set of edges, where each edge is a pair of vertices (u,v)

- Directed graph: edges have a direction
- Undirected graph: edges do not have a direction

- Weighted graph: edges have values/weights (costs, distances, etc.)
- Unweighted graph: edges do not have weights

- Path: A sequence of vertices connected by edges
- Cycle: A path that starts and ends at the same vertex without repeating any edges

- Degree: The number of edges connected to a vertex (undirected graph)
    For directed graphs:
    - In-degree: Number of incoming edges to a vertex 
    - Out-degree: Number of outgoing edges from a vertex 

- Ways of representation:
    - Adjacency Matrix: A 2D array where the entry at row i and column j indicates the presence (and possibly weight) of an edge from vertex i to vertex j.
    - Adjacency List: A list where each vertex has a list of adjacent vertices (and possibly weights).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; //n : no. of vertices, m : no. of edges
    cout << "Enter no. of vertices: ";
    cin >> n;
    cout << "Enter no. of edges: ";
    cin >> m;

    // Adjacency List (undirected graph)
    cout << "Enter edges (u v): " << endl;
    unordered_map<int, list<int>> adjList1;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjList1[u].push_back(v);
        adjList1[v].push_back(u); //since it's undirected
    }

    cout << "\nAdjacenct List: " << endl;
    for(auto &it : adjList1) {
        cout << it.first << " -> ";
        for(auto &v : it.second) {
            cout << v << " ";
        }
        cout << endl;
    }


    // Adjacency List (weighted undirected graph)
    cout << "\nEnter edges with weights (u v w): " << endl;
    unordered_map<int, list<pair<int,int>>> adjList2;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adjList2[u].push_back({v, w});
        adjList2[v].push_back({u, w}); //since it's undirected
    }

    cout << "\nAdjacency List (Weighted): " << endl;
    for (auto &it : adjList2) {
        cout << it.first << " -> ";
        for (auto &p : it.second) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
}