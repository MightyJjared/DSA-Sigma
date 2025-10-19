#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//the LCS is copy paste from previous , see striver dp lecture 31 for clariifction
/*
🔹 LeetCode Reference: 1092. Shortest Common Supersequence
- Given two strings text1 and text2, return **any shortest common supersequence (SCS)**.
- SCS is the smallest string that has both text1 and text2 as subsequences.
- Note: The problem itself only asks for the sequence, not the DP table or length.
- We are printing the DP table and length here **for clear understanding and visualization**.

Example:
    text1 = "brute", text2 = "groot"
    → One possible SCS: "bgrute"
    → SCS length = |text1| + |text2| - LCS_length = 5 + 5 - 4 = 6

🔹 Approach:
1. Compute **Longest Common Subsequence (LCS)** using DP.
2. Use LCS table to reconstruct one possible SCS string.
3. Formula for SCS length: SCS_length = |text1| + |text2| - LCS_length
*/

class Solution {
public:
    // Helper function to fill the dp table
    void longestCommonSubsequence(vector<vector<int>>& dp, string& text1, string& text2) {
        int i1 = text1.size();
        int i2 = text2.size();

        for (int i = 1; i <= i1; i++) {
            for (int j = 1; j <= i2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    int shortestCommonSupersequence(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();

        vector<vector<int>> dp(i1 + 1, vector<int>(i2 + 1, 0));

        // Fill the dp table using helper function
        longestCommonSubsequence(dp, text1, text2);

        int LCA = dp[i1][i2];
        int superSequenceLength = i1 + i2 - LCA;

        // Print dp table
        cout << "DP table :\n";
        for (int i = 0; i <= i1; i++) {
            for (int j = 0; j <= i2; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // Reconstruct sequence
        string answer;
        while (i1 > 0 && i2 > 0) {
            if (text1[i1 - 1] == text2[i2 - 1]) {
                answer += text1[i1 - 1];
                i1--;
                i2--;
            } 
            else if(dp[i1-1][i2] > dp[i1][i2-1]){
                answer += text1[i1-1];
                i1--;
            }
            else{
                answer += text2[i2-1];
                i2--;
            }
        }
        while(i1 > 0){
            answer += text1[i1-1];
            i1--;
        }
        while(i2 > 0){
            answer += text2[i2-1];
            i2--;
        }

        reverse(answer.begin(), answer.end());
        cout << "sequence = " << answer << endl;
        cout << endl;
        return superSequenceLength;
    }
};

int main() {
    Solution sol;

    // Example inputs
    string text1 = "brute";
    string text2 = "groot";
    int ans = sol.shortestCommonSupersequence(text1, text2);
    cout << "SCS length = " << ans << endl;

    return 0;
}
