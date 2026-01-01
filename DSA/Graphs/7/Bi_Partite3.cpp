#include <iostream>
#include <vector>
using namespace std;

// LeetCode 785: Is Graph Bipartite?
// A graph is bipartite if we can color all nodes using 2 colors
// such that no two adjacent nodes have the same color.

class Solution {
public:
    // DFS function to check bipartiteness
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& bipartite) {

        // Assign color to current node
        bipartite[node] = color;

        // Visit all adjacent nodes
        for(auto itr : graph[node]) {

            // If adjacent node is not colored yet
            if(bipartite[itr] == -1) {

                // Assign opposite color and continue DFS
                if(!dfs(itr, !color, graph, bipartite))
                    return false;
            }
            else {
                // If adjacent node has the same color
                // then graph is NOT bipartite
                if(bipartite[itr] == color)
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // bipartite[i] = -1  -> unvisited
        // bipartite[i] = 0/1 -> color
        vector<int> bipartite(n, -1);

        // Graph may be disconnected
        for(int i = 0; i < n; i++) {
            if(bipartite[i] == -1) {
                if(!dfs(i, 0, graph, bipartite))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example graph:
    // 0 -- 1
    // |    |
    // 3 -- 2
    // This graph is bipartite
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if(sol.isBipartite(graph))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is NOT Bipartite" << endl;

    return 0;
}
