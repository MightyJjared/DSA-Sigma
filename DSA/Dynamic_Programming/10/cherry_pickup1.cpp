#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    long long helper(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m){
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m){ // out of bound base case
            return -1e9;
        }

        if(i == n-1){ // base case
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        // all 9 cases
        int maximum = -1e9;
        for(int a = -1; a <= 1; a++){
            for(int b = -1; b <= 1; b++){
                int value = helper(i+1, j1+a, j2+b, grid, n, m);
                if(j1 == j2){
                    value += grid[i][j1];
                }
                else{
                    value += grid[i][j1] + grid[i][j2];
                }
                maximum = max(maximum, value);
            }
        }
        return maximum;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return helper(0,0,m-1,grid, n, m);
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
