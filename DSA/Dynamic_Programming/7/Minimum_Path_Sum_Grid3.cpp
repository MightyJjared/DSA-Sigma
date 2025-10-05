#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// tabulation
// LeetCode 64: Minimum Path Sum
// Explain: You need to go from top-left to bottom-right of a grid,
// moving only right or down, with minimum sum of path.
// Problem: Given a 2D grid of non-negative numbers, start at the top-left cell (0,0) and move only right or down until you reach the bottom-right cell (m-1,n-1). 
// The task is to find the path with the minimum possible sum of values along the way.
// Example: For grid = [[1,3,1],[1,5,1],[4,2,1]], valid paths include:
//   - 1 → 3 → 1 → 1 → 1 = 7 (minimum path sum)
//   - 1 → 3 → 5 → 1 → 1 = 11
//   - 1 → 1 → 5 → 1 → 1 = 9
// Therefore, the minimum path sum is 7.


class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        for(int i =0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i > 0){
                        up = dp[i-1][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = min(up, left) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        return helper(m, n, grid, dp);
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    Solution sol;
    cout << "Minimum Path Sum: " << sol.minPathSum(grid) << endl;
    return 0;
}
