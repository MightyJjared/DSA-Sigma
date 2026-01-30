#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

/*
LeetCode 1334
Find the City With the Smallest Number of Neighbors at a Threshold Distance

Approach:
- Floyd–Warshall (All-Pairs Shortest Path)
- Count reachable cities within distanceThreshold
- If tie, choose the city with the greatest index
*/
/*
Time Complexity:
- Floyd–Warshall algorithm runs in O(n^3)
- Counting reachable cities takes O(n^2)
- Overall Time Complexity: O(n^3)

Space Complexity:
- Adjacency matrix of size n x n → O(n^2)
- Map for storing counts → O(n)
- Overall Space Complexity: O(n^2)
*/


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));

        // Distance to itself = 0
        for(int i = 0; i < n; i++){
            adj[i][i] = 0;
        }

        // Fill edges
        for(auto itr : edges){
            int v = itr[0];
            int u = itr[1];
            int wt = itr[2];
            adj[v][u] = wt;
            adj[u][v] = wt;
        }

        // Floyd–Warshall
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][k] != 1e9 && adj[k][j] != 1e9){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        // Count reachable cities
        map<int,int> m;
        for(int i = 0; i < n; i++){
            m[i] = 0;
            for(int j = 0; j < n; j++){
                if(i != j && adj[i][j] <= distanceThreshold){
                    m[i]++;
                }
            }
        }

        // Find answer city
        int ans = 0;
        int minCount = INT_MAX;

        for(int i = 0; i < n; i++){
            if(m[i] <= minCount){
                minCount = m[i];
                ans = i;   // larger index chosen on tie
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };
    int distanceThreshold = 4;

    cout << "Answer city: "
         << sol.findTheCity(n, edges, distanceThreshold) << endl;

    return 0;
}
