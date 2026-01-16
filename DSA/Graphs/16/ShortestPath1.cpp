#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Reference: Problem format from GeeksforGeeks (Shortest Path in Weighted Undirected Graph)
// this is my own code wirth my own logic and this is accepted on geekforgeeks
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // Part 1 Initialization
        vector<int> ans;
        vector<pair<int, int>> adj[n+1];
        for(auto itr : edges){
            int u = itr[0];
            int v = itr[1];
            int wt = itr[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> distance(n+1, 1e9);
        distance[1] = 0;
        
        priority_queue<
        pair<vector<int>, vector<int>>,
        vector<pair<vector<int>, vector<int>>>,
        greater<pair<vector<int>, vector<int>>>
        > pq;
        
        // Part 2 declaring values
        vector<int> a = {0, 1}; // (total distance, node)
        vector<int> b = {1};
        pq.push({a, b});
        
        // Part 3 Applying dijkstras
        while(pq.size() > 0){
            vector<int> info = pq.top().first;
            vector<int> path = pq.top().second;
            
            int totalDistance = info[0];
            int node = info[1];
            
            pq.pop();
            
            for(auto itr : adj[node]){
                int v = itr.first;
                int wt = itr.second;

                if(distance[v] > distance[node] + wt){
                  distance[v] = distance[node] + wt;

                 path.push_back(v);

                 vector<int> newinfo = {distance[v], v};
                 pq.push({newinfo, path});

                // update answer if v == n
                if(v == n){
                   ans = path;
                  }

                 path.pop_back();
                }

            }
                
        }

        vector<int> dummy = {-1};
        if(distance[n] == 1e9){ // no path exists
            return dummy;
        }
        else{
            ans.insert(ans.begin(), distance[n]);
            return ans;
        }
    }
};

int main() {
    Solution obj;

    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    vector<int> ans = obj.shortestPath(n, m, edges);

    cout << "Output: ";
    for(int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
