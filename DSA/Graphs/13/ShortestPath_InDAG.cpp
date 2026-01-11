#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

// here this is a way to perofrm shortest distance for each node from a source node like dijakstras , here the logic
// is we will first perform toposort then create a dist array and mark the source node distance as 0 and 
// all others as 1e9 then we remove each elemnt from stack and perform edge relation on its neighbours
/*
G-27: Shortest Path in a Directed Acyclic Graph (DAG)

You are given a directed acyclic graph with N nodes and weighted edges.
The task is to compute the shortest distance from a given source node
(usually node 0) to every other node in the graph.

Typical approach:
1. Perform a topological sort of the graph.
2. Relax edges in topological order to update shortest distances.
3. Nodes unreachable from source keep distance as INF.
*/

class Solution {
public:
    void toposort(int node, vector<vector<pair<int,int>>>& adj, vector<int> &visited, stack<int> &s){
        visited[node] = true;

        for(auto itr : adj[node]){
            if(visited[itr.first] == false){
                toposort(itr.first, adj, visited, s);
            }
        }
        s.push(node);
    }
    vector<int> shortestPathDAG(int N, int M, vector<vector<pair<int,int>>>& adj, int src) {
        // TODO: write your topological sort + shortest path logic here
        vector<int> visited(N, 0);
        stack<int> s;
    
        for(int i =0; i < N; i++){
            if(visited[i] == false){
                toposort(i,adj,visited, s);
            }
        }


        vector<int> dist(N, 1e9); // placeholder, update in your logic
        dist[src] = 0;

        while(s.size() > 0){
            int node = s.top();
            s.pop();

            for(auto itr : adj[node]){
                int u = itr.first;
                int wt = itr.second;

                // edge relaxation
                if(dist[node] + wt < dist[u]){
                    dist[u] = dist[node] + wt;
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;

    int N = 6; // Example number of nodes
    int M = 7; // number of edges


    // adjacency list: adj[u] = list of {v, weight}
    vector<vector<pair<int,int>>> adj(N);

    // Example edges (u -> v with weight w)
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[4].push_back({2, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int src = 0;

    vector<int> dist = sol.shortestPathDAG(N, M, adj, src);

    cout << "Shortest distances from source " << src << ":\n";
    for(int i = 0; i < N; i++){
        cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
