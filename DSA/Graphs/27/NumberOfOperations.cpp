#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode Reference:
1319. Number of Operations to Make Network Connected
https://leetcode.com/problems/number-of-operations-to-make-network-connected/

Approach:
- Use Disjoint Set Union (Union by Rank + Path Compression)
- If number of edges < n-1 → impossible
- Count number of connected components
- Minimum operations required = components - 1

Time Complexity:
- DSU initialization: O(n)
- Union operations: O(m * α(n)) ≈ O(m)
- Counting components: O(n)
- Overall: O(n + m)

Space Complexity:
- parent[] + rank[] = O(n)
*/

class disjoint {
public:
    vector<int> rank;
    vector<int> parent;
    int n;

    disjoint(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findparent(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = findparent(parent[x]); // path compression
    }

    void unionbyrank(int A, int B) {
        int parA = findparent(A);
        int parB = findparent(B);

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(size < n - 1) {
            return -1;
        }

        disjoint ds(n);

        for(auto itr : connections) {
            int u = itr[0];
            int v = itr[1];
            ds.unionbyrank(u, v);
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) {
                count++;
            }
        }

        return count - 1;
    }
};

int main() {
    // Example input
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 2}
    };

    Solution sol;
    cout << "Minimum operations required: "
         << sol.makeConnected(n, connections) << endl;

    return 0;
}
