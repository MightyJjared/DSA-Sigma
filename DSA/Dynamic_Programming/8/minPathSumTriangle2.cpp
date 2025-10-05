#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoization (although this is correct with optimal timee complexity, it is exceeding tle in leetcode)
/*
LeetCode 120: Triangle (Minimum Path Sum in a Triangular Grid)
--------------------------------------------------------------
You are given a triangle array, return the minimum path sum from top to bottom.
At each step, you may move to the adjacent numbers in the row below.

Example:
Input: [[2],[3,4],[6,5,7],[4,1,8,3]]
Paths:
  2 -> 3 -> 5 -> 1 = 11
  2 -> 3 -> 5 -> 8 = 18
  2 -> 4 -> 7 -> 3 = 16
Minimum path sum = 11
*/

class Solution {
public:
    int helper(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == n){
            dp[row][col] = triangle[row][col];
            return dp[row][col];
        } 

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int same = triangle[row][col] + helper(row+1, col, n, triangle, dp);
        int next = triangle[row][col] + helper(row+1, col+1, n, triangle, dp);

        dp[row][col] = min(same, next);
        return dp[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, 0, n-1, triangle, dp);
    }
};

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    Solution sol;
    cout << "Minimum Path Sum in Triangle: " << sol.minimumTotal(triangle) << endl;

    return 0;
}
