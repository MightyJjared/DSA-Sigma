#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// this function  longestCommonSubsequence is exactly copied , see strivers dp 30 to understand (only 7 min)
/*
LeetCode 583 — Delete Operation for Two Strings
------------------------------------------------
Approach:
We use the concept of the Longest Common Subsequence (LCS).
To make both strings equal, we must delete characters that are not part of the LCS.
Hence, total operations = deletions from word1 + deletions from word2.

Formula:
    minDeletions = (len(word1) - LCS) + (len(word2) - LCS)

Example 1:
    word1 = "sea", word2 = "eat"
    LCS = "ea" → length = 2
    Deletions = (3 - 2) + (3 - 2) = 2

Example 2:
    word1 = "leetcode", word2 = "etco"
    LCS = "etco" → length = 4
    Deletions = (8 - 4) + (4 - 4) = 4
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();
        vector<vector<int>> dp(i1 + 1, vector<int>(i2 + 1, 0));

        for(int i = 0; i <= i1; i++) dp[i][0] = 0; // base case
        for(int j = 0; j <= i2; j++) dp[0][j] = 0; // base case

        for(int i = 1; i <= i1; i++){
            for(int j = 1; j <= i2; j++){
                if(text1[i-1] == text2[j-1]){ // match case
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else { // not match case
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[i1][i2];
    }

    int minDistance(string word1, string word2) {
        int LCS = longestCommonSubsequence(word1, word2);
        int n = word1.size(), m = word2.size();
        return (n - LCS) + (m - LCS);
    }
};

int main() {
    Solution sol;
    cout << sol.minDistance("sea", "eat") << endl;       // Output: 2
    cout << sol.minDistance("leetcode", "etco") << endl; // Output: 4
    return 0;
}
