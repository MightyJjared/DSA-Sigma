#include <iostream>
#include <vector>
using namespace std;
// leetcode 207
// here we are apllying not topological but directed cycle grapg detection usin dfs, this is not prferred
/*
   Question:
   You are given 'numCourses' courses and a list of prerequisite pairs.
   Each pair [a, b] means you must take course 'b' before course 'a'.
   Return true if you can finish all courses (i.e., no cycles in prerequisites),
   otherwise return false.

   Approach:
   - Represent the problem as a Directed Graph where edge b -> a means "b before a".
   - Use DFS with a recursion stack (recPath) to detect cycles.
   - If a cycle exists, return false (impossible to finish all courses).
   - If no cycle exists, return true.
*/

bool isCyclic(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &prerequisites) {
    visited[src] = true;
    recPath[src] = true;

    for(int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];

        if(src == u) {
            if(visited[v] == false) {
                if(isCyclic(v, visited, recPath, prerequisites) == true) {
                    return true;
                }
            }
            else if(recPath[v] == true) {
                return true;
            }
        }
    }

    recPath[src] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    int v = numCourses;
    vector<bool> visited(v, false);
    vector<bool> recPath(v, false);

    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            if(isCyclic(i, visited, recPath, prerequisites) == true) {
                return false;  // cycle detected
            }
        }
    }
    return true;  // no cycle
}

int main() {
    int numCourses = 4;

    // prerequisites: each pair [a, b] means "to take a, you must first take b"
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };

    if(canFinish(numCourses, prerequisites)) {
        cout << "All courses can be finished." << endl;
    } else {
        cout << "Not possible to finish all courses (cycle detected)." << endl;
    }

    return 0;
}
