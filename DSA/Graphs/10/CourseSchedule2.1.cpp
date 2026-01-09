#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// here we are using bfs using toposort, this one is easy and also just a line extension of CourseSchedule1.1
/*
LeetCode Problem: Course Schedule II (LC 210)
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
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

        if(answer.size() == n){ // if size is egual to n then return the answer vector
            return answer;
        }
        else{
            return {}; // else return an empty vector
        }
    }
};

int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> graph = {{1,0},{2,0},{3,1},{3,2}}; 
    // sample from LeetCode: possible order = 0,1,2,3 or 0,2,1,3

    vector<int> result = sol.findOrder(numCourses, graph);

    if(result.empty()){
        cout << "[]" << endl;
    } else {
        for(int x : result){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
