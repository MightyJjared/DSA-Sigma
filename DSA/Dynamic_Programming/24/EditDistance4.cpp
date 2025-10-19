#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation 
/*
🔹 LeetCode Reference: 72. Edit Distance
-------------------------------------------------
🧠 Problem:
Given two strings word1 and word2, return the minimum number of operations required 
to convert word1 to word2. You can insert, delete, or replace a character.

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: horse -> rorse (replace 'h' with 'r')
             rorse -> rose  (remove 'r')
             rose  -> ros   (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i =0; i <= m; i++){ // base case
            dp[0][i] = i;
        }
        for(int i =0; i <= n; i++){ // base case
            dp[i][0] = i;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]; // No operation needed
                }
                else{
                    int insertOp = 1 + dp[i][j-1];
                    int deleteOp = 1 + dp[i-1][j];
                    int replaceOp = 1 + dp[i-1][j-1];
                    dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution sol;

    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum operations to convert '" << word1 
         << "' to '" << word2 << "' = " 
         << sol.minDistance(word1, word2) << endl;

    string word3 = "intention";
    string word4 = "execution";
    cout << "Minimum operations to convert '" << word3 
         << "' to '" << word4 << "' = " 
         << sol.minDistance(word3, word4) << endl;

    return 0;
}
