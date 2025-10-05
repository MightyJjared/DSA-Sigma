#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursive
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
    int helper(int row, int col, int n, vector<vector<int>>& triangle){
        if(row == n) {
            return triangle[row][col];
        }

        int down = triangle[row][col] + helper(row+1, col, n, triangle);
        int diagonal = triangle[row][col] + helper(row+1, col+1, n, triangle);

        return min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return helper(0, 0, n-1, triangle);
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
