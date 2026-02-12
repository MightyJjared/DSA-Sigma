#include <iostream>
#include <vector>
using namespace std;

// here in building adjacency list we are using vector<vector<int>> l(n) ie 2d vector instead of vector<int> l[n]
// or list<int> l[n] because of some compiler issue
/*
🔹 LeetCode Reference: 547. Number of Provinces
------------------------------------------------
There are n cities. Some of them are connected, while some are not. 
If city A is directly connected with city B, and city B is directly connected with city C, 
then city A is indirectly connected with city C.

A province is a group of directly or indirectly connected cities, and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, and 0 otherwise.

Return the total number of provinces.
*/

class Solution {
public:
    void dfs(int i, vector<vector<int>> &l, int n, vector<bool> &visited) {
        visited[i] = true;

        for (auto itr : l[i]) {
            if (visited[itr] == false) {
                dfs(itr, l, n, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> l(n);  // adjacency list

        // Building adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    l[i].push_back(j);
                    l[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        // Counting connected components (provinces)
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i, l, n, visited);
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of Provinces: " << sol.findCircleNum(isConnected) << endl;

    return 0;
}
