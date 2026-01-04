
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 802: Find Eventual Safe States
/*
first of all the logic is if a node is part of a cycle or if it is connceting to a cycle then it cant be safe node
everything else if safe node
Approach - we are copying the exact code of cycle checking for directed graph and add an extra array check
now see in isCycle the for loop part means it is still not decide weather a  node is in cycle or not but if a node
crossed the fro loop part it is clear that it cant be in cycle or part of a cycle so then we mark that node as 1 
means it is safe node  then in main fuction we are copying that check array to answer arrya and returning it.
*/

class Solution {
public:
    bool isCycle(int node,
                 vector<vector<int>>& graph,
                 vector<bool>& visited,
                 vector<bool>& recPath,
                 vector<bool>& check) {

        visited[node] = true;
        recPath[node] = true;
        check[node] = 0;   // assume unsafe initially

        for (int itr : graph[node]) {
            if (!visited[itr]) {
                if (isCycle(itr, graph, visited, recPath, check)) {
                    check[itr] = 0;
                    return true;
                }
            } else if (recPath[itr]) {
                check[itr] = 0;
                return true;
            }
        }

        check[node] = 1;   // safe node
        recPath[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> recPath(n, false);
        vector<bool> check(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                isCycle(i, graph, visited, recPath, check);
            }
        }

        vector<int> answer;
        for (int i = 0; i < n; i++) {
            if (check[i]) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};

int main() {
    Solution sol;

    // Example graph
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> safeNodes = sol.eventualSafeNodes(graph);

    cout << "Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
 
    cout << endl;
    return 0;
}
