#include <iostream>
#include <vector>
using namespace std;

// Undirected, unweighted graph
class Graph {
    int v;
    vector<vector<int>> l;

public:
    Graph(int v) {
        this->v = v;
        l.resize(v);   // create v empty adjacency lists
    }

    void addedge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // because undirected
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
};

int main() {
    Graph graph(5);

    graph.addedge(0, 1);
    graph.addedge(1, 2);
    graph.addedge(1, 3);
    graph.addedge(2, 3);
    graph.addedge(2, 4);

    graph.print();

    return 0;
}
