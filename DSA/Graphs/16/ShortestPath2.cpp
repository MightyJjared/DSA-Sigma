#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Reference: GeeksforGeeks problem "Shortest Path in Weighted Undirected Graph"
// This is striver method lecture 35 where e are applying normal dijkstaras but also mainting a parent vector
// and initializing the parent vector with the index itself then updating parent only when relxation condition is
// true

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // part 1 Initialization
        vector<int> ans;
        vector<int> distance (n+1, 1e9);
        vector<int> parent (n+1, 0);
        
        // Building adjacency list
        vector<pair<int, int>> adj [n+1];
        for(auto itr : edges){
            int u = itr[0];
            int v = itr[1];
            int wt = itr[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;
        
        // Setting values
        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }
        
        distance[1] = 0;
        pq.push({0, 1}); // (totalDistance, node)
        
        // Applying Dijkstras
        while(!pq.empty()){
            int totalDistance = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            for(auto itr : adj[node]){
                int neighbour = itr.first;
                int wt = itr.second;
                if(distance[neighbour] > distance[node] + wt){
                    distance[neighbour] = distance[node] + wt;
                    
                    // updating parent node
                    parent[neighbour] = node;
                    
                    pq.push({distance[neighbour], neighbour});
                    
                }
            }
        }
        
        // Getting values form parent vector to ans vector
        int index = n;
        ans.push_back(n);
        while(parent[index] != index){
            ans.push_back(parent[index]);
            index = parent[index];
        }
        ans.push_back(1);
        ans.push_back(distance[n]);

        reverse(ans.begin(), ans.end());
        
        if(distance[n] == 1e9){
            return {-1};
        }
        else{
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
