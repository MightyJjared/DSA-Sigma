#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
        LeetCode 516: Longest Palindromic Subsequence
        Approach: Reverse the string and find LCS(s, reversed(s))
    */
    int LCA(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i == 0 || j == 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i-1] == t[j-1]){ // match case
            return dp[i][j] = 1 + LCA(i-1, j-1, s, t, dp);
        }
        else{
            return dp[i][j] = max(LCA(i-1, j, s, t, dp), LCA(i, j-1, s, t, dp));
        }
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int i = s.size();
        int j = t.size();
        vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
        return LCA(i, j, s, t, dp);
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence Length = " 
         << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
