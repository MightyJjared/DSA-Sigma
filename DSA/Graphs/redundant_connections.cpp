#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode 684: Redundant Connection
----------------------------------
Problem:
We are given a connected undirected graph with n nodes and n edges.
Originally, the graph was a tree (n nodes, n-1 edges = no cycle). 
But one extra edge was added, making it n edges → which always creates a cycle.
We need to return that extra edge.

Why does one extra edge create a cycle?
---------------------------------------
A tree has exactly one unique path between any two nodes.
When we add one more edge (u, v), and there is already a path 
from u to v, this edge creates a cycle.

Example:
Suppose we have edges:
    1 -- 2
    |    
    3

Initially (3 edges, 3 nodes): it’s a tree.
If we add edge (2,3):

      1
     / \
    2---3

Now there is a cycle: 1 → 2 → 3 → 1

Approach (Union-Find / Disjoint Set Union):
-------------------------------------------
1. Each node starts as its own parent (self loop).
2. For each edge (u, v):
   - If u and v are already in the same set (find(u) == find(v)):
       → Adding (u, v) would connect two nodes that already 
         have a path, so it must be the redundant edge.
   - Otherwise, merge their sets using union by rank.
3. The first edge that satisfies "already connected" is the answer.

This uses:
- Path Compression in find() → O(α(N)) amortized
- Union by Rank → keeps tree flat
*/

class Solution {
public:
    int find(int x, vector<int> &parent, vector<int> &rank){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x], parent, rank); // Path compression
    }

    void unionbyRank(int u, int v, vector<int> &parent, vector<int> &rank){
        int parU = find(u, parent, rank);
        int parV = find(v, parent, rank);

        if(parU == parV) return;

        // Union by rank
        if(rank[parU] == rank[parV]){
            parent[parV] = parU;
            rank[parU]++;
        }
        else if(rank[parU] > rank[parV]){
            parent[parV] = parU;
        }
        else{
            parent[parU] = parV;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> rank(n+1, 0);
        vector<int> ans;

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        for(int i = 0; i < n; i++){
            int src = edges[i][0];
            int neighbour = edges[i][1];

            int u = find(src, parent, rank);
            int v = find(neighbour, parent, rank);
             
            if(u != v){
                unionbyRank(u, v, parent, rank);
            }
            else{
                ans.push_back(src);
                ans.push_back(neighbour);
                break;
            }
        }
        return ans;
    }    
};

int main() {
    Solution sol;

    // Example input: edges form a cycle with the last edge [2,3]
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    
    vector<int> redundant = sol.findRedundantConnection(edges);

    cout << "Redundant edge: [" << redundant[0] << ", " << redundant[1] << "]" << endl;

    return 0;
}
