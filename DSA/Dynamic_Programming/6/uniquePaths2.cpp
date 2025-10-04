#include <iostream>
#include <vector>
using namespace std;

// memoization
/*
LeetCode 62: Unique Paths (Memoization)
Question: You are given an m x n grid. You start at the top-left corner (0,0) 
and can only move either down or right. Find the number of unique paths 
to reach the bottom-right corner (m-1,n-1).
Example: For a 3x3 grid, output = 6
*/

int helper(int m, int n, vector<vector<int>> &dp) {
    if (m == 0 && n == 0) return 1; // reached start
    if (m < 0 || n < 0) return 0;   // out of bounds

    if (dp[m][n] != -1) return dp[m][n]; // already computed

    int up = helper(m - 1, n, dp);    // move up
    int left = helper(m, n - 1, dp);  // move left

    dp[m][n] = up + left;
    return dp[m][n];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, dp); // adjust for 0-based indexing
}

int main() {
    int m = 3, n = 3;
    cout << "Unique paths for " << m << "x" << n << " grid: " 
         << uniquePaths(m, n) << endl;
    return 0;
}
