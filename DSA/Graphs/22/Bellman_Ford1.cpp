#include <iostream>
#include <vector>
using namespace std;

// This is strivers method
/*
Here this is like dijkstras as we use the same edge relaxation technique but here the difference is
1 - We dont convert the edges vector to adjcency list as here the order dont matter
2 - here we run the loop for V-1 times as it will garuntee that at max in V-1 times it will compute us the shortest
distances for each vertex
3 - It also helps us to know if a negative cycle exists
4 - In Dijkstras we cant use any negative edge but here we can use negative weights
Time Complexity - 
// Outer loop runs (V-1) times
// Inner loops traverse all edges E each time
// Total complexity = O(V * E)
*/
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // Part 1 Initialization
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i =0; i < V-1; i++){
            for(auto itr : edges){
                int v = itr[0];
                int u = itr[1];
                int wt = itr[2];
                
                if(dist[v] != 1e8){
                    if(dist[v] + wt < dist[u]){ // edge relaxation
                        dist[u] = dist[v] + wt;
                    }
                }
            }
        }
        
        for(auto itr : edges){ // 1 more iteration to see if negative cycle exists
            int v = itr[0];
            int u = itr[1];
            int wt = itr[2];
                
            if(dist[v] != 1e8){
                if(dist[v] + wt < dist[u]){ // edge relaxation
                    return {-1};
                }
            }
        }
        return dist;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    Solution sol;
    vector<int> result = sol.bellmanFord(V, edges, 0);

    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
