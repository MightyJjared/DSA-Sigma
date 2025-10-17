#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation

/*
🔹 LeetCode Reference: 1143. Longest Common Subsequence
🔹 Problem Explanation:
- Given two strings text1 and text2, find the length of the longest subsequence common to both.
- A subsequence appears in the same relative order but not necessarily contiguous.
- Example: text1 = "abcde", text2 = "ace" → LCS = "ace", length = 3

🔹 Approach Explanation (Tabulation):
- We use a 2D dp table (vector of vectors) where dp[i][j] stores the length of LCS 
  of text1[0..i-1] and text2[0..j-1].
- Why tabulation instead of memoization (recursion + cache):
    1. Iterative → no recursion stack overhead, safe for large inputs.
    2. Easier to reconstruct the actual LCS string.
    3. Computes each subproblem exactly once, slightly faster in practice.
- Base case: LCS of any string with empty string is 0 → first row and column initialized to 0.
- Filling table:
    • If characters match (text1[i-1] == text2[j-1]): dp[i][j] = 1 + dp[i-1][j-1].
    • If characters don’t match: dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
- Printing dp table: helps visualize how LCS lengths are computed for all prefixes.
- Reconstructing LCS:
    • Start from dp[i1][i2] and move backwards.
    • If characters match, add to answer and move diagonally up-left.
    • Else move in the direction of the larger value (up or left).
    • Reverse the string at the end since we built it backwards.
- Printing the LCS string: shows the actual sequence, not just its length.
*/

class Solution {
public:
    void longestCommonSubsequence(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();

        vector<vector<int>> dp(i1+1, vector<int>(i2+1, 0));

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
        for(int i =0; i<= i1; i++){
            for(int j =0; j <= i2; j++){
                cout << dp[i][j] << " "; // print dp table to visualize LCS length computation
            }
            cout << endl;
        }
        
        int length = dp[i1][i2];
        string ans;


        while(i1 > 0 && i2 > 0){
            if(text1[i1-1] == text2[i2-1]){
                ans += text1[i1-1];
                i1--;
                i2--;
            }
            else if(dp[i1-1][i2] > dp[i1][i2-1]){
                    i1--;
                }
            else if(dp[i1][i2-1] > dp[i1-1][i2]){
                    i2--;
                }
        }
        reverse(ans.begin(), ans.end());
        cout << "Longest Subsequence = " << ans << endl; // print the actual LCS sequence
    }
};

int main() {
    Solution sol;

    // Example inputs
    string text1 = "abcde";
    string text2 = "ace";

    sol.longestCommonSubsequence(text1, text2);

    return 0;
}
