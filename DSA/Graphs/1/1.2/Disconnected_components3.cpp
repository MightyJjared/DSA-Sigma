// GFG: https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

class Solution {
  public:
    void dfs(int node, vector<int> &currentResult, vector<bool> &visited, vector<vector<int>> &adj){
        visited[node] = true;
        
        currentResult.push_back(node);
        
        for(auto neighbours : adj[node]){
            if(visited[neighbours] == false){
                dfs(neighbours, currentResult, visited, adj);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> result;
        
        vector<vector<int>> adj(V);
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                vector<int> currentResult;
                dfs(i, currentResult, visited, adj);
                result.push_back(currentResult);
            }
        }
        
        return result;
    }
    
    // Time Complexity: O(V + E)
    // Space Complexity: O(V + E)
};