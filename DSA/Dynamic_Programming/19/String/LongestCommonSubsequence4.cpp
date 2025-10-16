#include <iostream>
#include <vector>
#include <string>
using namespace std;

// tabulation

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
    int longestCommonSubsequence(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();

        vector<vector<int>> dp(i1+1, vector<int>(i2+1, -1));

        for(int i =0; i <= i1; i++){ //base case
            dp[i][0] = 0;
        }
        for(int i =0; i <= i2; i++){ // base case
            dp[0][i] = 0;
        }

        for(int i =1; i <= i1; i++){
            for(int j = 1; j <= i2; j++){
                if(text1[i-1] == text2[j-1]){ // match case
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    int not_match1 = dp[i-1][j];
                    int not_match2 = dp[i][j-1];
                    dp[i][j] = max(not_match1, not_match2);
                }
            }
        }
        return dp[i1][i2];
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
