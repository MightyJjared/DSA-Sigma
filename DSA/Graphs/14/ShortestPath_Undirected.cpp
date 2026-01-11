#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
G-28: Shortest Path in Undirected Graph with Unit Weights

You are given an undirected graph with N nodes (0 to N-1) and M edges.
Each edge has unit weight (i.e., weight = 1).
The task is to compute the shortest distance from a given source node
to all other nodes in the graph.

Typical Approach:
Since all edges have equal weight, BFS will compute shortest paths efficiently.
Steps:
1. Build adjacency list for the undirected graph.
2. Perform BFS from the source node.
3. Track minimum distances using a distance array.
4. Nodes unreachable from the source remain at INF (or -1 based on choice).
*/

class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& adj, int src) {
        // TODO: write your BFS shortest path logic here
         
        vector<int> dist(N, 1e9); // placeholder; you will update this
        dist[src] = 0;
        queue<int> q;

        q.push(src);
        while(q.size() > 0){
            int node = q.front();
            q.pop();

            for(auto itr : adj[node]){
                if(dist[node] + 1 < dist[itr]){
                    dist[itr] = dist[node] + 1;
                    q.push(itr);
                }
            }
        }
        vector<int> ans(N, -1);
        for(int i =0; i < N; i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }

        return ans;
    }
};

int main() {
    int N = 9; // example number of nodes
    int M = 10; // example number of edges

    // adjacency list representation
    vector<vector<int>> adj(N);

    // example undirected edges (unit weight)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);

    adj[2].push_back(6);
    adj[6].push_back(2);

    adj[6].push_back(7);
    adj[7].push_back(6);

    adj[7].push_back(8);
    adj[8].push_back(7);

    int src = 0; // starting point for BFS

    Solution sol;
    vector<int> dist = sol.shortestPath(N, M, adj, src);

    cout << "Shortest distances from source " << src << ":\n";
    for(int i = 0; i < N; i++){
        cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
