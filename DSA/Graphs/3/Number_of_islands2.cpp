#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// bfs approach (not preferred)
/*
🔹 LeetCode Reference: 200. Number of Islands
---------------------------------------------
Given an m x n grid, count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
*/

class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>>& grid, int n, int m) {
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});

        // Directions: up, left, right, down
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};

        while (!q.empty()) {
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int trow = frontRow + drow[k];
                int tcol = frontCol + dcol[k];

                if (trow >= 0 && trow < n && tcol >= 0 && tcol < m &&
                    visited[trow][tcol] == false && grid[trow][tcol] == '1') {
                    visited[trow][tcol] = true;
                    q.push({trow, tcol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        // Scan every cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    bfs(i, j, visited, grid, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of Islands: " << sol.numIslands(grid) << endl;
    return 0;
}
