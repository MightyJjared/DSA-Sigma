#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// here longestPalindromeSubseq and LCA fuction is copy paste form previous files
/*
LeetCode 1312 — Minimum Insertion Steps to Make a String Palindrome
-------------------------------------------------------------------
Approach:
We use the concept of the Longest Palindromic Subsequence (LPS).
The minimum number of insertions required to make a string palindrome
is the number of characters not part of the LPS.

Formula:
    minInsertions = n - LPS

We find LPS by taking the original string 's' and its reverse 't',
then computing the Longest Common Subsequence (LCS) between them.

Example 1:
    s = "mbadm"
    Reverse = "mdabm"
    LPS = "mam" → length = 3
    minInsertions = 5 - 3 = 2

Example 2:
    s = "leetcode"
    Reverse = "edocteel"
    LPS = "ete" → length = 3
    minInsertions = 8 - 3 = 5
*/

class Solution {
public:
    int LCA(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        for(int n = 0; n <= i; n++){ // base case: empty string
            dp[0][n] = 0;
        }
        for(int n = 0; n <= j; n++){ // base case: empty string
            dp[n][0] = 0;
        }

        for(int n = 1; n <= i; n++){
            for(int m = 1; m <= j; m++){
                if(s[n-1] == t[m-1]){ // match case
                    dp[n][m] = 1 + dp[n-1][m-1];
                } else { // not match case
                    dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
                }
            }
        }
        return dp[i][j];       
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int i = s.size();
        int j = t.size();
        vector<vector<int>> dp(i+1, vector<int>(j+1, 0));
        return LCA(i, j, s, t, dp);
    }

    int minInsertions(string s) {
        int n = s.size();
        int LPS = longestPalindromeSubseq(s);
        return n - LPS;
    }
};

int main() {
    Solution sol;
    cout << sol.minInsertions("mbadm") << endl;     // Output: 2
    cout << sol.minInsertions("leetcode") << endl;  // Output: 5
    return 0;
}
