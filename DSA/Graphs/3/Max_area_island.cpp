#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode 695: Max Area of Island
---------------------------------
You are given an m x n binary grid where:
  - 0 → water
  - 1 → land

An island is a group of connected 1's (connected 4-directionally: up, down, left, right).
We need to find the area of the largest island (maximum number of connected 1's).

Approach:
---------
- We use DFS (Depth First Search) to explore each island.
- For every unvisited land cell (grid[i][j] == 1), we start DFS to calculate its area.
- DFS marks the land as visited and recursively explores its 4 neighbors.
- For each island, we keep track of the area and update the maximum area found so far.

Time Complexity: O(n * m) → each cell is visited once.
Space Complexity: O(n * m) → visited matrix + recursion stack.
*/

class Solution {
public:
    int dfs(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<bool>> &visited, int &count){
        visited[row][col] = true;
        count++;

        // up
        if(row-1 >=0 && visited[row-1][col] == false && grid[row-1][col] == 1){
            dfs(row-1, col, n, m, grid, visited, count);
        }

        // down
        if(row+1 < n && visited[row+1][col] == false && grid[row+1][col] == 1){
            dfs(row+1, col, n, m, grid, visited, count);
        }

        // left
        if(col-1 >= 0 && visited[row][col-1] == false && grid[row][col-1] == 1){
            dfs(row, col-1, n, m, grid, visited, count);
        }

        // right
        if(col+1 < m && visited[row][col+1] == false && grid[row][col+1] == 1){
            dfs(row, col+1, n, m, grid, visited, count);
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int max_count =0;

        for(int i =0; i< n; i++){
            for(int j =0; j< m; j++){
                int count =0;
                if(grid[i][j] == 1 && visited[i][j] == false){
                    max_count = max (max_count, dfs(i, j, n, m ,grid, visited, count));
                }
            }
        }
        return max_count;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,1,1},
        {0,1,1,0,1,0,1,0},
        {0,0,0,0,1,0,0,0},
        {1,1,0,0,1,1,0,0}
    };

    int result = sol.maxAreaOfIsland(grid);

    cout << "Max Area of Island: " << result << endl;

    return 0;
}
