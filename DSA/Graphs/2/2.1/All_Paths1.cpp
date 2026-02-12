#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Directed graph: print all paths from src to dest

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
    }

    void dfs_helper(int src, int dest,
                    vector<bool>& visited,
                    vector<int>& path) {

        visited[src] = true;
        path.push_back(src);

        if (src == dest) {
            // print path
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            for (int nbr : l[src]) {
                if (!visited[nbr]) {
                    dfs_helper(nbr, dest, visited, path);
                }
            }
        }

        // backtrack
        path.pop_back();
        visited[src] = false;
    }

    void all_paths(int src, int dest) {
        vector<bool> visited(v, false);
        vector<int> path;
        dfs_helper(src, dest, visited, path);
    }
};

int main() {
    Graph graph(6);

    graph.addedge(0, 3);
    graph.addedge(2, 3);
    graph.addedge(3, 1);
    graph.addedge(4, 0);
    graph.addedge(4, 1);
    graph.addedge(5, 0);
    graph.addedge(5, 2);

    graph.all_paths(5, 1);

    return 0;
}
