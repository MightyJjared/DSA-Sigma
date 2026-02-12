#include <iostream>
#include <vector>
using namespace std;

// Undirected, weighted graph
class Graph {
    int v;
    vector<vector<pair<int, int>>> l; 
    // pair<neighbor, weight>

public:
    Graph(int v) {
        this->v = v;
        l.resize(v);
    }

    void addedge(int u, int v, int wt) {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt}); // undirected
    }

    void print() {
        for (int i = 0; i < v; i++) {
            cout << i << " : ";
            for (auto nbr : l[i]) {
                cout << "(" << nbr.first << ", " << nbr.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);

    graph.addedge(0, 1, 4);
    graph.addedge(1, 2, 2);
    graph.addedge(1, 3, 6);
    graph.addedge(2, 3, 1);
    graph.addedge(2, 4, 3);

    graph.print();

    return 0;
}
