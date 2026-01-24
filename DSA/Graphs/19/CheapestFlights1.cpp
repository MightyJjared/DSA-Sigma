#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Strivers method this one is preferred
// LeetCode 787: Cheapest Flights Within K Stops
// Time Complexity:  O(m * k)
// Space Complexity: O(m + n * k)
// where:
//   n = number of cities
//   m = number of flights
//   k = max allowed stops

/*
here the intution is simple we are applying dijkstras but every time we prioritze weight in priorit queue but this time
we are prioritizing stops and since stops will increase gradually one by one so we dont need priority queue 
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Part 1 Initialization
        queue<pair<int, pair<int, int>>> pq;

        // Building adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(auto itr : flights){
            int v = itr[0];
            int u = itr[1];
            int distance = itr[2];

            adj[v].push_back({u, distance});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        pq.push({{0}, {src, 0}}); //({stops}, {node, distance})

        while(pq.size() > 0){
            int stops = pq.front().first;
            int node = pq.front().second.first;
            int distance = pq.front().second.second;
            pq.pop();
            
            if(stops > k){
                continue;
            }

            for(auto itr : adj[node]){
                int wt = itr.second;
                int currentNode = itr.first;
                int total_distance = wt + distance;
                if(total_distance < dist[currentNode] && stops <= k){
                    dist[currentNode] = total_distance;
                    pq.push({{stops+1}, {currentNode, total_distance}});
                }
            }
        }

        if(dist[dst] == 1e9){
            return -1;
        }
        else{
            return dist[dst];
        }
    }
};

int main() {
    // sample test for VS Code
    int n = 3;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };
    int src = 0;
    int dst = 2;
    int k = 1;

    Solution s;
    int ans = s.findCheapestPrice(n, flights, src, dst, k);
    cout << ans << endl; // expected output: 200

    return 0;
}
