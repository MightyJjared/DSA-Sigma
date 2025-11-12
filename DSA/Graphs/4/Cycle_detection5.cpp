#include <iostream>
#include <vector>
#include <list>
using namespace std;

// DFS-based Cycle Detection in an Undirected, Possibly Disconnected Graph
// ------------------------------------------------------------
// 1️⃣ If neighbour is unvisited → recurse deeper (DFS).
// 2️⃣ If neighbour is visited and not parent → cycle detected.
// 3️⃣ Check all disconnected components (not just one).

class Graph {
    int v;
    list<int>* l;

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool helper(int source, int parent, vector<bool>& visited) {
        visited[source] = true;

        for (auto itr : l[source]) {
            if (!visited[itr]) {
                if (helper(itr, source, visited)) {
                    return true; // cycle found in recursion
                }
            } 
            else if (itr != parent) {
                // visited and not parent → back edge → cycle
                return true;
            }
        }
        return false;
    }

    bool cycle_detection() {
        vector<bool> visited(v, false);

        // run DFS for every unvisited node → handles disconnected graph
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (helper(i, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph graph(6);

    // Component 1: no cycle
    graph.addedge(0, 1);
    graph.addedge(1, 2);

    // Component 2: has cycle (3-4-5-3)
    graph.addedge(3, 4);
    graph.addedge(4, 5);
    graph.addedge(5, 3);

    if (graph.cycle_detection()) {
        cout << "Cycle exists";
    } else {
        cout << "Cycle doesn't exist";
    }
    cout << endl;

    return 0;
}
