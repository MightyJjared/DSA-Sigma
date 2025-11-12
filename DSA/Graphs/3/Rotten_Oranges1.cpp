#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// this one is preferred (reference striver g 10)
// this can done only using bfs
/*
🔹 LeetCode 994: Rotting Oranges
--------------------------------
You are given an m x n grid where:
  0 → empty cell
  1 → fresh orange
  2 → rotten orange

Each minute, any fresh orange that is 4-directionally adjacent 
to a rotten one becomes rotten.

Return:
  - The minimum number of minutes until no cell has a fresh orange.
  - If impossible, return -1.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();             // number of rows
        int m = grid[0].size();          // number of columns
        
        // visited matrix to keep track of already rotten or processed cells
        vector<vector<int>> visited(n, vector<int>(m, false));

        // queue will store ((row, col), time)
        queue<pair<pair<int, int>, int>> q;

        // Step 1: Push all initially rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2 && visited[i][j] == false) {
                    q.push({{i, j}, 0});   // push cell with time = 0
                    visited[i][j] = true;  // mark as visited
                }
            }
        }

        // directions: up, right, left, down
        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, 1, -1, 0};
        int minute = 0;   // to track the total time taken

        // Step 2: Perform BFS to rot nearby fresh oranges
        while (q.size() > 0) {
            int crow = q.front().first.first;    // current row
            int ccol = q.front().first.second;   // current column
            int ctime = q.front().second;        // current time (minutes passed)
            minute = max(minute, ctime);         // update total time
            q.pop();                             // remove processed cell

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nextRow = crow + delrow[i];
                int nextCol = ccol + delcol[i];

                // Check bounds + if cell has a fresh orange (1) + not visited yet
                if (nextRow >= 0 && nextRow < n &&
                    nextCol >= 0 && nextCol < m &&
                    grid[nextRow][nextCol] == 1 &&
                    visited[nextRow][nextCol] == false) {

                    visited[nextRow][nextCol] = true;  // mark as visited
                    grid[nextRow][nextCol] = 2;        // mark orange as rotten
                    q.push({{nextRow, nextCol}, ctime + 1});  // push with +1 minute
                }
            }
        }

        // Step 3: Check if any fresh oranges remain after BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;   // still fresh orange → impossible to rot all
                }
            }
        }

        // Step 4: Return total minutes required to rot all oranges
        return minute;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // Expected output → 4
    cout << "Minutes to rot all oranges: " << sol.orangesRotting(grid) << endl;

    return 0;
}
