#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Problem: LeetCode 1976 (Number of Ways to Arrive at Destination)
/*
The intution is completely different and but code is exact dijksta  but one condition extra inside the for loop by
adding ways arrray
Time complexity = Of dijkstra ie E log V
space complexity = V + E same of dijkstra
*/

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto itr : roads){
            int v = itr[0];
            int u = itr[1];
            int wt = itr[2];

            adj[v].push_back({u, wt});
            adj[u].push_back({v, wt});
        }

        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        
        priority_queue<
        pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<pair<long long, long long>>
        > pq;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        pq.push({0, 0}); // (distance, node)

        long long mod = 1e9 + 7;

        while(pq.size() > 0){
            long long distance = pq.top().first;
            long long node = pq.top().second;

            pq.pop();

            for(auto itr : adj[node]){
                long long currentWeight = itr.second;
                long long currentNode = itr.first;

                long long totaldistance = currentWeight + distance;
                if(dist[currentNode] > totaldistance){
                    dist[currentNode] = totaldistance;
                    ways[currentNode] = ways[node];
                    pq.push({totaldistance, currentNode}); 
                }
                else if(dist[currentNode] == totaldistance){
                    ways[currentNode] = (ways[currentNode] + ways[node] )% mod;
                }
            }
        }
        
        return  ways[n-1] % mod;
    }
};

int main() {
    int n = 7;
    vector<vector<int>> roads = {
        {0,1,1},
        {0,2,1},
        {1,3,1},
        {2,3,1},
        {3,6,1},
        {1,4,2},
        {2,5,2},
        {4,6,2},
        {5,6,2}
    };

    Solution sol;
    cout << sol.countPaths(n, roads) << endl;

    return 0;
}
