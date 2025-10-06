#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int row =0; row < n; row++){
            for(int col =0; col < n; col++){
                if(row == 0){
                    dp[row][col] = matrix[row][col];
                }
                else{
                    int same = matrix[row][col] + dp[row-1][col];

                    int prev = 1e9;
                    if(col-1 >= 0){
                        prev = matrix[row][col] + dp[row-1][col-1];
                    }

                    int next = 1e9;
                    if(col + 1 < n){
                        next = matrix[row][col] + dp[row-1][col+1];
                    }

                    dp[row][col] = min(same, min(prev, next));
                }
            }
        }
        int minimum = 1e9;
        for(int i = 0; i < n; i++){
            minimum = min(minimum, dp[n-1][i]);
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
