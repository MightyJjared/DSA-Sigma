#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// see striver for explanation
/*
LeetCode 269: Alien Dictionary
---------------------------------------------
Approach:
1. Build graph:
   - Compare adjacent words in the dictionary.
   - Find the first different character -> add a directed edge (u -> v).
   - This gives us precedence constraints between characters.

2. Topological Sort:
   - Use DFS-based topological sort.
   - Once all neighbors of a node are processed, push it to a stack.
   - Pop elements from the stack to get a valid character order.

Note:
- We use `vector<int> adj[K];` for the adjacency list.
  This means `adj` is an array of K vectors,
  where each `adj[i]` stores all the neighbors of node i.
  Essentially: graph representation using arrays of dynamic arrays.
*/

class Solution {
public:
    void topological_helper(int v, stack<int> &s, vector<int> &visited, vector<int> adj[]) {
        visited[v] = true;
        for (auto itr : adj[v]) {
            if (visited[itr] == false) {
                topological_helper(itr, s, visited, adj);
            }
        }
        s.push(v);
    }

    stack<int> topological(int K, vector<int> adj[]) {
        stack<int> s;
        vector<int> visited(K, false);
        for (int i = 0; i < K; i++) {
            if (visited[i] == false) {
                topological_helper(i, s, visited, adj);
            }
        }
        return s;
    }

    string alienOrder(string dict[], int n, int K) {
        vector<int> adj[K];
        string ans = "";

        // Build graph from dictionary
        for (int i = 0; i < n - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int length = min(s1.size(), s2.size());
            for (int j = 0; j < length; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // Perform topological sort
        stack<int> s = topological(K, adj);
        while (!s.empty()) {
            char a = char(s.top() + 'a');
            s.pop();
            ans.push_back(a);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    string order = sol.alienOrder(dict, N, K);

    cout << "Alien Dictionary Order: " << order << endl;

    return 0;
}
