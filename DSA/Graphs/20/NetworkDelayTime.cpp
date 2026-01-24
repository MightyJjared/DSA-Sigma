#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// LeetCode 743: Network Delay Time
// just classic dikstras algoritm implementation
// time Complexity = E Log V
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Building adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto itr : times){
            int u = itr[0];
            int v = itr[1];
            int wt = itr[2];

            adj[u].push_back({v, wt});
        } 
        
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;

        pq.push({0, k}); // (distance, node)

        while(pq.size() > 0){
            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto itr : adj[node]){
                int currentWeight = itr.second;
                int currentNode = itr.first;

                int totalWeight = currentWeight + wt;
                if(totalWeight < dist[currentNode]){
                    dist[currentNode] = totalWeight;
                    pq.push({totalWeight, currentNode});
                }
            }
        }

        int ans = -1e9;
        for(int i =1; i <= n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};

int main() {
    // sample test for VS Code
    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    int n = 4;
    int k = 2;

    Solution s;
    int ans = s.networkDelayTime(times, n, k);
    cout << ans << endl; // expected output: 2

    return 0;
}
