#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1020: Number of Enclaves
// Problem:
// Count the number of land cells (1s) that cannot reach the boundary of the grid.
// Boundary-connected land cells are NOT enclaves.

class Solution {
public:
    // DFS to mark all land cells connected to the boundary
    void dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             int n, int m) {

        visited[row][col] = true;

        // up
        if (row - 1 >= 0 && grid[row - 1][col] == 1 && !visited[row - 1][col]) {
            dfs(row - 1, col, grid, visited, n, m);
        }

        // down
        if (row + 1 < n && grid[row + 1][col] == 1 && !visited[row + 1][col]) {
            dfs(row + 1, col, grid, visited, n, m);
        }

        // left
        if (col - 1 >= 0 && grid[row][col - 1] == 1 && !visited[row][col - 1]) {
            dfs(row, col - 1, grid, visited, n, m);
        }

        // right
        if (col + 1 < m && grid[row][col + 1] == 1 && !visited[row][col + 1]) {
            dfs(row, col + 1, grid, visited, n, m);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        // visited[i][j] = true means this land cell is connected to boundary
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        // Traverse first and last row
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 1 && !visited[0][i]) {
                dfs(0, i, grid, visited, row, col);
            }
            if (grid[row - 1][i] == 1 && !visited[row - 1][i]) {
                dfs(row - 1, i, grid, visited, row, col);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                dfs(i, 0, grid, visited, row, col);
            }
            if (grid[i][col - 1] == 1 && !visited[i][col - 1]) {
                dfs(i, col - 1, grid, visited, row, col);
            }
        }

        int count = 0;

        // Count all land cells NOT connected to boundary (enclaves)
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

/*
Time Complexity:
- O(N × M)
  Each cell is visited at most once.

Space Complexity:
- O(N × M)
  visited matrix + recursion stack in worst case.
*/

int main() {
    Solution sol;

    // Example grid
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    int result = sol.numEnclaves(grid);
    cout << "Number of Enclaves: " << result << endl;

    return 0;
}
