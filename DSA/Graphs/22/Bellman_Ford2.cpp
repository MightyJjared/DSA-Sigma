#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;
// -----------------------------
// Bellman-Ford Algorithm
// -----------------------------
// ✅ Works on directed weighted graphs
// ✅ Handles negative edge weights
// ❌ Fails if graph has a negative weight cycle
// Purpose: Find the shortest distance from a single source (src) to all other vertices
// -----------------------------
// In this code:
// - We assume edges can have negative weights
// - We represent graph using edge list (vector of edges per vertex)
// - Bellman-Ford runs in O(V * E)
// -----------------------------

class edge{
    public:
    int v;   // destination vertex
    int wt;  // weight of the edge

    edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int v, int src, vector<vector<edge>> graph){
    // Step 1: Initialize distance array
    // All vertices initially set to infinity (unreachable)
    // Distance to source = 0
    vector<int> distance(v, INT8_MAX); // should ideally be INT32_MAX, but here INT8_MAX used
    distance[src] = 0;

    // Step 2: Relax all edges (V-1) times
    // Why V-1 times? Because the longest possible path without a cycle 
    // can have at most V-1 edges.
    // Each iteration tries to improve the shortest paths found so far.
    for(int i =0; i <v-1; i++){  // repeat V-1 times
        for(int u = 0; u < v; u++){  // traverse all vertices
            for(auto itr : graph[u]){  // traverse all edges from u
                // Relaxation: check if going through u improves distance to itr.v
                if(distance[itr.v] > distance[u] + itr.wt){
                    distance[itr.v] = distance[u] + itr.wt;
                }
            }
        }
    }

    // Step 3: Print final shortest distances
    // (In a complete implementation we would also check for negative cycles 
    // by doing one more relaxation and seeing if any distance still improves.)
    for(auto itr : distance){
        cout << itr << " ";
    }
    cout << endl;
}

int main(){
    int v = 5;
    vector<vector<edge>> graph(v);

    // Graph edges (directed):
    // 0 -> 1 (2)
    // 0 -> 2 (4)
    // 1 -> 2 (-4)
    // 2 -> 3 (2)
    // 3 -> 4 (4)
    // 4 -> 1 (-1)
    graph[0].push_back(edge(1,2)); // (vertex, weight)
    graph[0].push_back(edge(2,4));

    graph[1].push_back(edge(2,-4));

    graph[2].push_back(edge(3,2));

    graph[3].push_back(edge(4,4));

    graph[4].push_back(edge(1,-1));
    
    // Run Bellman-Ford with source = 0
    bellmanFord(v, 0, graph);
    

    return 0;
}

// -----------------------------
// TIME COMPLEXITY ANALYSIS
// -----------------------------
// Outer loop runs (V-1) times
// Inner loops traverse all edges E each time
// Total complexity = O(V * E)
// -----------------------------
// SPACE COMPLEXITY
// Distance array of size V = O(V)
// Graph stored as adjacency list = O(V + E)
// -----------------------------
