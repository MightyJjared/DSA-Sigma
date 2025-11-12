#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// BFS-based cycle detection for an undirected, possibly disconnected graph.
// Handles all components by running BFS from every unvisited node.

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

    // Helper BFS function for one connected component
    bool bfs_cycle(int start, vector<bool>& visited) {
        queue<pair<int, int>> q;  // {current, parent}
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto itr : l[current]) {
                if (!visited[itr]) {
                    visited[itr] = true;
                    q.push({itr, current});
                } 
                else if (itr != parent) {
                    // visited & not parent → cycle exists
                    return true;
                }
            }
        }
        return false;
    }

    bool cycle_detection() {
        vector<bool> visited(v, false);

        // Check every disconnected component
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (bfs_cycle(i, visited)) {
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
