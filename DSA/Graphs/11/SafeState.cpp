#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// LeetCode Problem: Eventual Safe Nodes (LC 802)
// we already solved it previously using dfs cycle detection but this approach uses bfs and kahns algo
// now the logic is simple first we will reverse all the edges of the graph and just simply apply khans algo to
// reverse node who has indegree 0, it will give us the answers

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<int> q;

        vector<int> reverseGraph[n]; // building revrse graph ie with all edges reversed
        for(int i =0; i < n; i++){
            for(auto itr : graph[i]){
                reverseGraph[itr].push_back(i);
            }
        }

        vector<int> indegree(n,0);
        for(int i =0; i< n; i++){// calculating indegree of each node
            for(auto itr : reverseGraph[i]){
                indegree[itr]++;
            }
        }
        for(int i =0; i < n; i++){ // applying toposort
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(q.size() > 0){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto itr : reverseGraph[node]){
                indegree[itr]--;
                if(indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Example test case for VS Code
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    // Expected safe nodes for this example -> [2,4,5,6]

    vector<int> result = sol.eventualSafeNodes(graph);

    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
