#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// tabulation 
// we just copied LCA printing function fro previous file as it is
// LCA function is copied as it is from previous file
/*
    LeetCode 516: Longest Palindromic Subsequence
    ------------------------------------------------
    🔹 Problem:
       Find the length of the longest subsequence in a string 
       that is also a palindrome.

    🔹 Approach (Tabulation using LCS):
       - Reverse the string → let it be `t`.
       - Find the Longest Common Subsequence (LCS) between `s` and `t`.
       - The length of this LCS = length of the Longest Palindromic Subsequence.

    🔹 Why this works:
       A palindrome reads the same forward and backward, so its subsequence 
       must appear in both `s` and its reverse `t` in the same order.
*/

class Solution {
public:
    int LCA(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        for(int n = 0; n <= i; n++){ // base case
            dp[0][n] = 0;
        }
        for(int n = 0; n <= j; n++){ // base case
            dp[n][0] = 0;
        }

        for(int n = 1; n <= i; n++){
            for(int m = 1; m <= j; m++){
                if(s[n-1] == t[m-1]){ // match case
                    dp[n][m] = 1 + dp[n-1][m-1];
                }
                else{ // not match case
                    dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
                }
            }
        }
        int answer = dp[i][j];
        int length = dp[i][j];
        string ans;
        while(i > 0 && j > 0){
            if(s[i-1] == t[j-1]){
                ans += s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "Longest palndrome is : " << ans << endl;
        return answer;
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int i = s.size();
        int j = t.size();
        vector<vector<int>> dp(i+1, vector<int>(j+1, 0));
        int ans = LCA(i, j, s, t, dp);

        for(int n = 0; n<= i; n++){
            for(int m =0; m <= j; m++){
                cout << dp[n][m] << " ";
            }
            cout << endl;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    int ans = sol.longestPalindromeSubseq(s);
    cout << "Longest Palindromic Subsequence Length = " << ans << endl;
    return 0;
}
