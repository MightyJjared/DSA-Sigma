#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Reference:
GeeksforGeeks — Kruskal’s Minimum Spanning Tree (MST) Algorithm

Approach:
- Convert edge list to (weight, (u, v)) format
- Sort edges by weight
- Use Disjoint Set Union (Union by Rank + Path Compression)
- Pick edges that do not form a cycle

Time Complexity:
- Sorting edges: O(E log E)
- DSU operations: O(E * α(V)) ≈ O(E) (almost constant)
- Overall: O(E log E)

Space Complexity:
- DSU arrays: O(V)
- Extra edge list (edges2): O(E)
- Overall: O(V + E)
*/

class DisjointSet {
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]); // path compression
    }

    void unionByRank(int A, int B) {
        int parA = find(A);
        int parB = find(B);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            parent[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]) {
            parent[parB] = parA;
        }
        else {
            parent[parA] = parB;
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {

        vector<pair<int, pair<int,int>>> edges2;

        // Rearranging edges to (weight, (u, v))
        for(auto &e : edges) {
            edges2.push_back({e[2], {e[0], e[1]}});
        }

        // Sort edges by weight
        sort(edges2.begin(), edges2.end());

        int sum = 0;
        DisjointSet ds(V);

        for(auto itr : edges2) {
            int u = itr.second.first;
            int v = itr.second.second;
            int wt = itr.first;

            if(ds.find(u) != ds.find(v)) {
                sum += wt;
                ds.unionByRank(u, v);
            }
        }

        return sum;
    }
};

int main() {
    // Example graph
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Solution sol;
    cout << "Weight of MST: " << sol.kruskalsMST(V, edges) << endl;

    return 0;
}
