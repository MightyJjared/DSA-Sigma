#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Number of Provinces Leetcode 547
Approach: Disjoint Set Union (Union by Rank + Path Compression)

Time Complexity:
- Building unions from matrix: O(n^2 * α(n)) ≈ O(n^2)
- Counting parents: O(n)

Space Complexity:
- DSU arrays: O(n)
*/

class DisjointSet {
public:
    int n;
    vector<int> parent;
    vector<int> rank;

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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionByRank(i, j);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    // Example input
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;
    cout << "Number of Provinces: "
         << sol.findCircleNum(isConnected) << endl;

    return 0;
}
