#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

/*
LeetCode 1584: Min Cost to Connect All Points
https://leetcode.com/problems/min-cost-to-connect-all-points/

Approach:
- This is a Minimum Spanning Tree (MST) problem on a COMPLETE graph.
- We apply Prim's algorithm without a priority queue.
- Since the graph is complete, each node is connected to every other node,
  so we can compute edge weights (Manhattan distance) on the fly.

Time Complexity:
- O(n^2)
  * We select the minimum edge vertex n times (O(n) each time).
  * For each selected vertex, we update distances to all other vertices (O(n)).

Space Complexity:
- O(n)
  * mst[] and minDist[] arrays.
*/


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> mst(n, false);
        vector<int> minDist(n, INT_MAX);

        minDist[0] = 0;   // start from node 0
        int minCost = 0;
        int connected = 0;

        while (connected < n) {
            int u = -1;
            int mini = INT_MAX;

            // find minimum distance unvisited node
            for (int i = 0; i < n; i++) {
                if (!mst[i] && minDist[i] < mini) {
                    mini = minDist[i];
                    u = i;
                }
            }

            // add node u to MST
            mst[u] = true;
            minCost += mini;
            connected++;

            // update distances
            for (int i = 0; i < n; i++) {
                if (!mst[i]) {
                    int wt = abs(points[u][0] - points[i][0]) +
                             abs(points[u][1] - points[i][1]);
                    minDist[i] = min(minDist[i], wt);
                }
            }
        }

        return minCost;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << sol.minCostConnectPoints(points) << endl;
    return 0;
}
