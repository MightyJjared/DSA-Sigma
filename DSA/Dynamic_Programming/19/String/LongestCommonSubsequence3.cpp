#include <iostream>
#include <vector>
#include <string>
using namespace std;

// memoization
// here since in previous our base case was checking when i was negative we cant use that in tabulation
// thats why we just changed the indexing to +1 ie f(1) means f(0) and f(0) now means f(-1)
// we only chnaged the size of vector<vector from i to i+1 and when calling helper first time we passed i intead of
// i-1 and inside helper  we wrote i-1 when checking the match case intead of i
/*
🔹 LeetCode Reference: 1143. Longest Common Subsequence
🔹 Problem Explanation:
- Given two strings text1 and text2.
- Find the length of the longest subsequence common to both strings.
- A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
- Example: text1 = "abcde", text2 = "ace" → LCS = "ace", length = 3
*/

class Solution {
public:
    int helper(int i1, int i2, string &text1, string &text2, vector<vector<int>> &dp){
        if(i1 == 0 || i2 == 0) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(text1[i1-1] == text2[i2-1]) // match case
            return dp[i1][i2] = 1 + helper(i1-1, i2-1, text1, text2, dp);

        // not match case
        int not_match1 = helper(i1-1, i2, text1, text2, dp);
        int not_match2 = helper(i1, i2-1, text1, text2, dp);
        return dp[i1][i2] = max(not_match1, not_match2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();
        vector<vector<int>> dp(i1+1, vector<int>(i2+1, -1));
        return helper(i1, i2, text1, text2, dp);
    }
};

int main() {
    Solution sol;

    // Example inputs
    string text1 = "abcde";
    string text2 = "ace";

    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of LCS = " << result << endl;

    return 0;
}
