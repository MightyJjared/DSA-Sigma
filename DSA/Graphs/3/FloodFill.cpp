#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode Reference: Problem 733. Flood Fill
https://leetcode.com/problems/flood-fill/

Question:
You are given a 2D image represented as a matrix. Each cell in the matrix 
contains a color (integer). Starting from a given (sr, sc) pixel, 
perform a "flood fill" where you change the color of the starting pixel 
and all connected pixels (connected means 4-directionally: up, down, left, right) 
that have the same original color, into a new given color.

Example:
Input:
image = [[1,1,1],
         [1,1,0],
         [1,0,1]]
sr = 1, sc = 1, color = 2

Output:
[[2,2,2],
 [2,2,0],
 [2,0,1]]

Approach:
- Use DFS (Depth First Search) starting from (sr, sc).
- Maintain a visited matrix to avoid infinite loops.
- For each cell, check 4 directions (up, down, left, right).
- Recurse only if:
  1. The new cell is inside bounds.
  2. It is not already visited.
  3. Its color matches the original color of (sr, sc).
- Replace its color with the new color.
- Time Complexity: O(N * M) where N = rows, M = columns (since each cell is visited at most once).
*/

class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<int>>& image, vector<vector<bool>>& visited, int color, int oldcolor){
        visited[row][col] = true;
        image[row][col] = color;

        // down
        if(row+1 < n && !visited[row+1][col] && image[row+1][col] == oldcolor){
            dfs(row+1, col, n, m, image, visited, color, oldcolor);
        }

        // up
        if(row-1 >= 0 && !visited[row-1][col] && image[row-1][col] == oldcolor){
            dfs(row-1, col, n, m, image, visited, color, oldcolor);
        }

        // left
        if(col-1 >= 0 && !visited[row][col-1] && image[row][col-1] == oldcolor){
            dfs(row, col-1, n, m, image, visited, color, oldcolor);
        }

        // right
        if(col+1 < m && !visited[row][col+1] && image[row][col+1] == oldcolor){
            dfs(row, col+1, n, m, image, visited, color, oldcolor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); // rows
        int m = image[0].size(); // columns

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(sr, sc, n, m, image, visited, color, image[sr][sc]);
        return image;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    cout << "Flood filled image:" << endl;
    for(auto row : result){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
