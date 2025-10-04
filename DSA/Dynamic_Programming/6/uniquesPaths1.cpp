#include <iostream>
#include <vector>
using namespace std;

// recursive
/*
LeetCode 62: Unique Paths
Question: You are given an m x n grid. You start at the top-left corner (0,0) 
and can only move either down or right. Find the number of unique paths 
to reach the bottom-right corner (m-1,n-1).
Example: For a 3x3 grid, output = 6
*/

int helper(int m, int n) {
    if (m == 0 && n == 0) return 1; // reached start
    if (m < 0 || n < 0) return 0;   // out of bounds

    int up = helper(m - 1, n);      // move up
    int left = helper(m, n - 1);    // move left
    return up + left;
}

int uniquePaths(int m, int n) {
    return helper(m - 1, n - 1); // adjust for 0-based indexing
}

int main() {
    int m = 3, n = 3;
    cout << "Unique paths for " << m << "x" << n << " grid: " 
         << uniquePaths(m, n) << endl;
    return 0;
}
