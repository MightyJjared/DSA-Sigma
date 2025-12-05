#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// memoization
// LeetCode 64: Minimum Path Sum
// Explain: You need to go from top-left to bottom-right of a grid,
// moving only right or down, with minimum sum of path.

class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(m < 0 || n < 0){
            return 1e9;
        }
        if(m ==0 && n== 0){
            return grid[0][0];
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int up = helper(m-1,n,grid,dp) + grid[m][n];
        int left = helper(m,n-1,grid,dp) + grid[m][n];


        dp[m][n] = min(up,left);
        return dp[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, grid, dp);
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
