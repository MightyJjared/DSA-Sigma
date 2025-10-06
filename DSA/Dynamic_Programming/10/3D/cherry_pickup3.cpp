#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation
/*
LeetCode 1463: Cherry Pickup II
You are given a rows x cols grid representing a field of cherries.
Two robots start at the top row (one at (0,0) and the other at (0, cols-1)) 
and move to the bottom row. On each step, both robots can move left, right, or down.
They pick cherries from the cells they visit (a cell’s cherries can be counted only once).

Goal: Return the maximum number of cherries collected by both robots.

Example:
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: 
Path of robot #1: (0,0) → (1,0) → (2,1) → (3,1)
Path of robot #2: (0,3) → (1,2) → (2,2) → (3,2)
Total cherries = 3+2+5+1 + 1+1+5+5 = 24
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m)));
        
        for(int j1 =0; j1 < m; j1++){ // base case (altough it is tabulation but we are going top down intead of bottom up)
            for(int j2 =0; j2 < m; j2++){
                if(j1 == j2){
                    dp[n-1][j1][j2] = grid[n-1][j1];
                }
                else{
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }

        for(int i = n-2; i >= 0; i--){ // these 3 for loops because we have 1 same row and 2 col
            for(int j1 = 0; j1 < m; j1++){
                for(int j2 =0; j2 < m; j2++){

                    int maximum = -1e9/2; // copy paste from memoization
                    for(int a = -1; a <= 1; a++){
                        for(int b = -1; b <= 1; b++){
                            int value = 0;
                            if(j1+a < m && j2+b < m && j1 +a >= 0 && j2+b >= 0){ // just added t                                                                   this exa out of boounds check
                                value = dp[i+1][j1+a][j2+b]; 
                            }
                            if(j1 == j2){
                               value += grid[i][j1];
                           }
                           else{
                              value += grid[i][j1] + grid[i][j2];
                            }
                            maximum = max(maximum, value);
                        }
                    }
                    dp[i][j1][j2] = maximum;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };
    cout << "Maximum cherries collected: " << sol.cherryPickup(grid) << endl;
    return 0;
}
