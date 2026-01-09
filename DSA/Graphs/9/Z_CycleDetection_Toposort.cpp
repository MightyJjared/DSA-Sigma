#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// Question: Detect whether a directed graph contains a cycle.
// Approach: Use Topological Sort (Kahn's Algorithm - BFS)
//
// Idea:
// 1) Compute indegree of all nodes.
// 2) Push nodes with indegree 0 into queue.
// 3) Perform BFS and reduce indegree of neighbours.
// 4) Count how many nodes are processed.
// 5) If processed nodes < total nodes → cycle exists.
//
// Why it works:
// In a DAG, every node can be placed in topological order.
// If a cycle exists, some nodes will never reach indegree 0.

class Graph {
    int v;
    list<int>* l;

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    // Directed edge
    void addedge(int u, int v) {
        l[u].push_back(v);
    }

    void print() {
        for (int i = 0; i < v; i++) {
            cout << i << " : ";
            for (int nbr : l[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    bool cycle_detection() {
        vector<int> indegree(v, 0);

        // Step 1: Calculate indegree
        for (int i = 0; i < v; i++) {
            for (int nbr : l[i]) {
                indegree[nbr]++;
            }
        }

        queue<int> q;

        // Step 2: Push nodes with indegree 0
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Step 3: BFS (Topological Sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int nbr : l[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // Step 4: If not all nodes are processed → cycle exists
        if(count == v){
            return false;
        }
        else{
            return true;
        }
    }
};

int main() {
    Graph graph(5);

    // Directed edges
    graph.addedge(0, 1);
    graph.addedge(1, 2);
    graph.addedge(2, 3);
    graph.addedge(3, 1); // creates a cycle
    graph.addedge(3, 4);

    cout << graph.cycle_detection();
    cout << endl;

    return 0;
}
