#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
LeetCode Reference:
947. Swim in Rising Water
https://leetcode.com/problems/swim-in-rising-water/

Approach:
- This is a classic Dijkstra-based shortest path problem on a grid.
- Each cell has a height; the cost of a path is the maximum height encountered so far.
- We use a min-priority queue where the key is the minimum possible "time" (max height so far).
- From the current cell, we explore all 4 directions and push the updated cost.
- The answer is determined when we reach the bottom-right cell.

Important Dijkstra Invariant:
- A node is marked visited ONLY when it is popped from the priority queue.
- This is because the first time a node is popped, we are guaranteed to have found
  the minimum possible cost to reach that node.
- Marking visited earlier (on push) can block a better path that arrives later.

Time Complexity:
- O(n^2 log(n^2)) ≈ O(n^2 log n)
  Each cell is processed once, and each push/pop costs log(n^2).

Space Complexity:
- O(n^2) for the visited matrix and priority queue.
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min-heap: (current max height so far, (row, col))
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        int r[] = {-1, 0, 0, 1};
        int c[] = {0, -1, 1, 0};

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}}); // (distance, current cell)

        while (!pq.empty()) {
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // We mark visited ONLY when popping because
            // this is the moment Dijkstra guarantees the shortest (minimum max-height) path.
            if (visited[row][col]) {
                continue;
            }
            visited[row][col] = true;

            for (int i = 0; i < 4; i++) {
                int newrow = row + r[i];
                int newcol = col + c[i];

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n) {
                    if (distance < grid[newrow][newcol]) {
                        int newdistance = grid[newrow][newcol];
                        if (newrow == n - 1 && newcol == n - 1) {
                            return newdistance;
                        }
                        pq.push({newdistance, {newrow, newcol}});
                    } else {
                        if (newrow == n - 1 && newcol == n - 1) {
                            return distance;
                        }
                        pq.push({distance, {newrow, newcol}});
                    }
                }
            }
        }
        return grid[0][0];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };

    cout << sol.swimInWater(grid) << endl;
    return 0;
}
