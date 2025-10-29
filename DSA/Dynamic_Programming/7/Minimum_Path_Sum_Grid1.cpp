#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// recursive
// LeetCode 64: Minimum Path Sum
// Explain: You need to go from top-left to bottom-right of a grid,
// moving only right or down, with minimum sum of path.

class Solution {
public:

    int helper(int m, int n, vector<vector<int>>& grid) {
        if(m < 0 || n < 0){
            return 1e9;
            }
        if(m ==0 && n== 0){
            return grid[0][0];
            }    
    
        int up = grid[m][n] + helper(m-1, n, grid);
        int left = grid[m][n] +  helper(m, n-1, grid);

                 
        return min(up, left);
}


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return helper(m-1, n-1, grid);
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