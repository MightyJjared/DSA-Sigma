#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// memoization (1 based indexing for tabulation)
/*
🔹 LeetCode Reference: 44. Wildcard Matching
-------------------------------------------------
🧠 Problem:
Given a string s and a pattern p, implement wildcard matching with support for 
'?' and '*'.
- '?' Matches any single character.
- '*' Matches any sequence of characters (including the empty sequence).

Return true if s matches the pattern p.

Example 1:
Input: s = "aa", p = "a*"
Output: true

Example 2:
Input: s = "cb", p = "?a"
Output: false
*/

class Solution {
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(j == 0 && i == 0){
            return true;
        }
        if(j == 0 && i > 0){
            return false;
        }
        if(i == 0 && j > 0){
            for(int k =1; k <= j; k++){
                if(p[k-1] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = helper(i-1, j-1, s, p, dp);
        }
        if(p[j-1] == '*'){
            bool case1 = helper(i-1, j, s, p, dp);
            bool case2 = helper(i , j-1, s, p, dp);
            if(case1 || case2){
                return dp[i][j] = true;
            }
            else{
                return dp[i][j] = false;
            }
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return helper(n, m, s, p, dp);
    }
};

int main() {
    Solution sol;

    string s1 = "aa", p1 = "a*";
    cout << "Input: s = " << s1 << ", p = " << p1 
         << "\nOutput: " << (sol.isMatch(s1, p1) ? "true ✅" : "false ❌") << "\n\n";

    string s2 = "cb", p2 = "?a";
    cout << "Input: s = " << s2 << ", p = " << p2 
         << "\nOutput: " << (sol.isMatch(s2, p2) ? "true ✅" : "false ❌") << "\n\n";

    string s3 = "adceb", p3 = "*a*b";
    cout << "Input: s = " << s3 << ", p = " << p3 
         << "\nOutput: " << (sol.isMatch(s3, p3) ? "true ✅" : "false ❌") << "\n";

    return 0;
}
