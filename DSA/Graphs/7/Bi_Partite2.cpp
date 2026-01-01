#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode 785: Is Graph Bipartite?
// A graph is bipartite if we can color each node using 2 colors
// such that no two adjacent nodes have the same color.

class Solution {
public:
    // Helper function to check bipartiteness of one connected component
    bool helper(int v, vector<vector<int>>& graph, vector<int> &bipartite){

        // Queue stores (node, color)
        queue<pair<int, int>> q; 

        // Assign color 0 to starting node
        bipartite[v] = 0;
        q.push({v, 0});

        // BFS traversal
        while(!q.empty()){
            int node = q.front().first;
            int color = q.front().second;
            q.pop();

            // Traverse all adjacent nodes
            for(auto itr : graph[node]){

                // If adjacent node is not colored yet
                if(bipartite[itr] == -1){
                    // Assign opposite color
                    bipartite[itr] = !color;
                    q.push({itr, !color});
                }
                else{
                    // If adjacent node has same color → not bipartite
                    if(bipartite[itr] == color){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // bipartite[i] = -1 → unvisited
        // bipartite[i] = 0 or 1 → color
        vector<int> bipartite(n, -1);

        // Graph may be disconnected
        for(int i = 0; i < n; i++){
            if(bipartite[i] == -1){
                if(helper(i, graph, bipartite) == false){
                    return false;
                }
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
