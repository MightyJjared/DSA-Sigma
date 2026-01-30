#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

/*
GeeksforGeeks Reference:
https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

This program implements Prim’s Algorithm using a priority queue
to find the Minimum Spanning Tree (MST) of an undirected weighted graph.
*/

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // Part 1 Initializations
        vector<vector<pair<int, int>>> adj(V);
        for(auto itr : edges){
            int v = itr[0];
            int u = itr[1];
            int wt = itr[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<
        pair<pair<int, int>, int>,
        vector<pair<pair<int, int>, int>>,
        greater<pair<pair<int, int>, int>>
        > pq;
        
        vector<bool> visited(V, false);
        vector<pair<int, int>> mst;
        int Sum = 0;
        
        // Part 2 While loop
        pq.push({{0, 0}, -1}); // ({weight, current node}, parent node)
        
        while(pq.size() > 0){
            int wt = pq.top().first.first;
            int currentnode = pq.top().first.second;
            int parentnode = pq.top().second;
            
            pq.pop();
            
            if(visited[currentnode] == false){
                visited[currentnode] = true;
                
                Sum += wt;
                mst.push_back({currentnode, parentnode});
                
                for(auto itr : adj[currentnode]){
                    int neighbour = itr.first;
                    int weight = itr.second;
                    pq.push({{weight, neighbour}, currentnode});
                }
            }
        }

        // Printing the MST edges (node - parent)
        cout << "MST edges (node -> parent):" << endl;
        for(auto itr : mst){
            cout << itr.first << " -> " << itr.second << endl;
        }

        return Sum;
    }
};

int main() {
    Solution sol;

    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };

    cout << "Weight of MST: "
         << sol.spanningTree(V, edges) << endl;

    return 0;
}
