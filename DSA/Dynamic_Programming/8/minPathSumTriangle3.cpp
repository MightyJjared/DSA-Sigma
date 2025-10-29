#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation
/*
LeetCode 120: Triangle (Minimum Path Sum)
-----------------------------------------
You are given a triangle array, return the minimum path sum from top to bottom.
At each step, you may move to the adjacent numbers in the row below.

Example:
Triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Possible paths:
   2 → 3 → 5 → 1 = 11
   2 → 3 → 5 → 8 = 18
   2 → 4 → 7 → 3 = 16
Answer = 11 (minimum path sum)
*/

class Solution {
public:
    int helper(int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        for(int i =0; i <n; i++){
            for(int j =0; j <= i; j++){
                if(i ==0 && j ==0){
                    dp[i][j] = triangle[i][j];
                }
                else{
                    int same = dp[i-1][j];
                    if(j == i){
                        same = 1e9;
                    }
                    int next = 1e9;
                    if(j > 0){
                        next = dp[i-1][j-1];
                    }
                    dp[i][j] = min(same, next) + triangle[i][j];
                }
            }
        }
        int minimum = 1e9;
        for(int i =0; i < n; i++){
            minimum = min(minimum, dp[n-1][i]);
        }
        return minimum;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        return helper(n,triangle, dp);
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
