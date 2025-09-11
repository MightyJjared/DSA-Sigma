#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/*
    Tarjan's Algorithm (for Bridges in an Undirected Graph)

    -----------------------------
    What is a Bridge?
    -----------------------------
    - An edge (u, v) is called a *bridge* if removing it increases 
      the number of connected components of the graph.
    - In other words, the edge is critical for connectivity.
      Without it, some vertices will become unreachable from others.

    Example:
        0 -- 1 -- 2
             |
             3
        Edge (1,2) is a bridge, because removing it disconnects vertex 2.

    Example:
              0
             / \
            1---2
             \
              3
               \
                4

        - Here, edge (3,4) is a BRIDGE.
          Because if we remove it, node 4 gets disconnected.
        - But edge (0,1) is NOT a bridge.
          Because even if we remove (0,1), we can still reach 1 through (0,2) -> (2,1)

    -----------------------------
    Idea of Tarjan's Algorithm:
    -----------------------------
    - Do a DFS traversal of the graph.
    - For each vertex, record two values:
        1. discovery_time[u] = the time when we first discover vertex u
        2. lowTime[u] = the earliest discovered vertex reachable from u
                        (including back edges)
    - For an edge (u, v):
        If discovery_time[u] < lowTime[v], then (u, v) is a bridge.

    -----------------------------
    Why pass 'time' by reference?
    -----------------------------
    - 'time' is a DFS timestamp that must be UNIQUE across the entire DFS.
    - If we pass 'time' by value, each recursive call only has a local copy,
      so when DFS backtracks and explores a new branch, the counter "rewinds"
      and discovery times may repeat.
    - By passing 'time' by reference, we ensure the counter increases globally
      across the entire DFS traversal.

    -----------------------------
    Alternate Approach:
    -----------------------------
    - Another way to find bridges is to remove each edge one by one and 
      run a BFS/DFS to check if the graph is still connected.
    - But that approach is very inefficient: O(E * (V+E)).
    - Tarjan’s algorithm does it in O(V + E) using one DFS traversal.
*/

class Graph {
    int v;             // number of vertices
    list<int>* l;      // adjacency list

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v) {
        l[u].push_back(v); 
        l[v].push_back(u); // undirected edge
    }

    void helper(int src, vector<int> &discovery_time, vector<int> &lowTime, 
                vector<bool> &visited, int &time, int parent) {
        visited[src] = true;

        // Increase global timestamp and assign discovery & low value
        time++;
        discovery_time[src] = lowTime[src] = time;

        // Explore neighbors
        list<int> neighbours = l[src];
        for (auto itr : neighbours) {
            if (itr == parent) {
                // Skip the edge to parent (don’t go back immediately)
                continue;
            } 
            else if (!visited[itr]) {
                // Tree edge (not visited yet)
                helper(itr, discovery_time, lowTime, visited, time, src);

                // After recursion, update lowTime of src
                lowTime[src] = min(lowTime[src], lowTime[itr]);

                // Bridge condition:
                if (discovery_time[src] < lowTime[itr]) {
                    cout << "Bridge is : " << src << "----" << itr << endl;
                }
            } 
            else {
                // Back edge (already visited neighbor, not parent)
                lowTime[src] = min(lowTime[src], discovery_time[itr]);
            }
        }
    }

    void tarjan() {
        vector<int> discovery_time(v);
        vector<int> lowTime(v);
        vector<bool> visited(v, false);
        int time = 0;

        // Run DFS from every unvisited node (to cover disconnected graphs)
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                helper(i, discovery_time, lowTime, visited, time, -1);
            }
        }
    }
};

int main() {
    Graph graph(6);

    graph.addedge(0,1);
    graph.addedge(0,2);
    graph.addedge(0,3);
    graph.addedge(1,2);
    graph.addedge(3,4);
    graph.addedge(3,5);
    graph.addedge(4,5);

    graph.tarjan();

    return 0;
}

