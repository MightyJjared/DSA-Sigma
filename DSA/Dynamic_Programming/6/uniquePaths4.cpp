// memoization
// it is completely same as uniques paths 1 we just added one edge case in both function ie
/*if(obstacleGrid[m][n] == 1){
        return 0;
    }
*/
/*
LeetCode 63: Unique Paths II
----------------------------
A robot is located at the top-left corner of an m x n grid.  
The robot can only move either down or right at any point in time.  

The grid may have obstacles marked with 1, and free cells with 0.  
The robot starts at (0,0) and needs to reach (m-1, n-1).  

Return the total number of unique paths the robot can take, avoiding obstacles.  
If the start or destination is blocked, return 0.
*/

#include <iostream>
#include <vector>
using namespace std;

int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
    if(m==0 && n==0){
        return 1;
    }
    if(m < 0 || n < 0){
        return 0;
    }
    if(obstacleGrid[m][n] == 1){
        return 0;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }

    int up = helper(m-1, n, obstacleGrid, dp);
    int left = helper(m, n-1, obstacleGrid, dp);
    dp[m][n] = up + left;
    return dp[m][n];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0] == 1){
        return 0;
    }
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m-1, n-1, obstacleGrid, dp);
}

int main() {
    // Example test case
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << "Unique paths with obstacles: " 
         << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
