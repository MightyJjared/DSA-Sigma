#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i][j] reperents the right bottom part of the squares(refeernce striver dp 56)
/*
LeetCode 1277: Count Square Submatrices with All Ones

🔹 Problem:
Given a binary matrix of 0s and 1s, count all square submatrices 
that contain only 1s.

🔹 Approach (Dynamic Programming):
For each cell (i, j), dp[i][j] represents the size of the largest 
square that ends at (i, j).  
If matrix[i][j] == 1:
    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
Otherwise:
    dp[i][j] = 0

Sum of all dp[i][j] gives the total number of square submatrices.

🔹 Example:
Input:
1 0 1
1 1 0
1 1 0

Output: 7
Explanation:
- 6 squares of size 1x1
- 1 square of size 2x2
Total = 7
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // Base case: first row and first column same as matrix
        for (int i = 0; i < row; i++) {
            dp[i][0] = matrix[i][0];
        }
        for (int j = 0; j < col; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the rest
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                count += dp[i][j];
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    cout << s.countSquares(matrix);
    return 0;
}

/*
✅ Example Output:
7
*/
