#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// leetcode 210
/*
   Question:
   You are given 'numCourses' courses and a list of prerequisite pairs.
   Each pair [a, b] means you must take course 'b' before taking course 'a'.
   Return a possible order in which you can finish all courses.
   If it is impossible (due to a cycle), return an empty list.

   Approach:
   - Model the problem as a Directed Graph where an edge b -> a means "b before a".
   - Step 1: Detect if a cycle exists using DFS + recursion path (recPath).
             If a cycle is found, return an empty list (no valid order).
   - Step 2: If no cycle, perform Topological Sorting using DFS and a stack.
             Pop elements from stack to get the valid course order.
*/

bool isCyclic(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &graph){
    visited[src] = true;
    recPath[src] = true;

    for(int i = 0; i < graph.size(); i++){
        int u = graph[i][1];
        int v = graph[i][0];

        if(u == src){
            if(visited[v] == false){
                if(isCyclic(v, visited, recPath, graph) == true){
                    return true;
                }
            }
            else if(recPath[v] == true){
                return true;
            }
        }
    }

    recPath[src] = false;
    return false;
}

void topological_order(int src, vector<bool> &visited1, stack<int> &s, vector<vector<int>> &graph){
    visited1[src] = true;

    for(int i = 0; i < graph.size(); i++){
        int u = graph[i][1];
        int v = graph[i][0];

        if(u == src){
            if(visited1[v] == false){
                topological_order(v, visited1, s, graph);
            }
        }
    }

    s.push(src);
}

vector<int> findOrder(int numCourses, vector<vector<int>> &graph){
    int V = numCourses;
    vector<bool> visited(V, false);
    vector<bool> recPath(V, false);
    vector<int> ans;

    // Step 1: Cycle detection
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            if(isCyclic(i, visited, recPath, graph) == true){
                return ans; // return empty if cycle
            }
        }
    }

    // Step 2: Topological order
    vector<bool> visited1(V, false);
    stack<int> s;
    vector<int> ans1;

    for(int i = 0; i < V; i++){
        if(visited1[i] == false){
            topological_order(i, visited1, s, graph);
        }
    }

    while(!s.empty()){
        ans1.push_back(s.top());
        s.pop();
    }

    return ans1;
}

int main(){
    int numCourses = 4;

    // prerequisites: each pair is [a, b] meaning "to take a, you must first take b"
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };

    vector<int> order = findOrder(numCourses, prerequisites);

    if(order.empty()){
        cout << "No valid order (cycle detected)" << endl;
    } else {
        cout << "Course order: ";
        for(int course : order){
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
