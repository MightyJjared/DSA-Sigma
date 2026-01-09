#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode Problem: Course Schedule (LC 207)
// here we are applying toposort using bfs but first converting the graph array to ajacency list 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int n = numCourses;
        vector<int> adj[n];

        for(int i =0; i < graph.size(); i++){ // building adjacency list 
            adj[graph[i][1]].push_back(graph[i][0]);
        } 

        // calculating indegree for toposort
        vector<int> indegree(n, 0);

        for(int i =0; i < n; i++){
            for(auto itr : adj[i]){
                indegree[itr]++;
            }
        }

        queue<int> q;
        
        // pushing nodes which have degree 0 into queue
        for(int i =0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> answer;
        while(q.size() > 0){
            int node = q.front();
            q.pop();

            answer.push_back(node);

            for(auto itr : adj[node]){
                indegree[itr]--;
                if(indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }

        if(answer.size() == n){
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example test for VS Code
    int numCourses = 2;
    vector<vector<int>> graph = {{1,0}}; // can take 1 after 0

    if(sol.canFinish(numCourses, graph)){
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
