#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// memoization
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
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        // Base cases
        if(i < 0) return j + 1; // Insert remaining characters of word2
        if(j < 0) return i + 1; // Delete remaining characters of word1

        // Check if already computed
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = helper(i-1, j-1, word1, word2, dp); // No operation needed
        }
        
        // else case
        int insertOp = 1 + helper(i, j-1, word1, word2, dp);
        int deleteOp = 1 + helper(i-1, j, word1, word2, dp);
        int replaceOp = 1 + helper(i-1, j-1, word1, word2, dp);
        dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
        

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, word1, word2, dp);
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
