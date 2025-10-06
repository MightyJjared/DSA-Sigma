#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoization (although this is correct with optimal time complexity, it is exceeding tle in leetcode)
/*
LeetCode 931: Minimum Falling Path Sum
Given an n x n integer matrix, return the minimum sum of a falling path through matrix.
A falling path starts at any element in the first row and chooses one element from each row.
The next row's choice must be in a column that is the same, or one column to the left or right of the previous row's column.

Example:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: The falling path 1 → 5 → 7 has the minimum sum 13.
*/

class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp){
        if(row == n){
            dp[row][col] = matrix[row][col];
            return dp[row][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col]; 
        }
        int same = matrix[row][col] + helper(row+1,col,matrix,n,dp);

        int next = 1e9;
        if(col+1 <= n){
            next = matrix[row][col] + helper(row+1,col+1,matrix,n,dp);
        }

        int prev = 1e9;
        if(col-1 >= 0){
            prev = matrix[row][col] + helper(row+1,col-1,matrix,n, dp);
        }
        
        dp[row][col] = min(same, min(prev,next));
        return dp[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minimum = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i =0; i < n; i++){
            minimum = min(helper(0,i,matrix, n-1, dp), minimum);
        }
        return minimum;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };
    cout << "Minimum Falling Path Sum: " << sol.minFallingPathSum(matrix) << endl;
    return 0;
}
