#include <iostream>
#include <vector>
#include <string>
using namespace std;

// tabulation (not preferred slightly harder , do memoization)
/*
🔹 LeetCode Reference: 44. Wildcard Matching
-------------------------------------------------
🧠 Problem:
Given a string `s` and a pattern `p` (which may include '?' and '*'),
return true if the string matches the pattern.

Rules:
- '?' matches any single character.
- '*' matches any sequence of characters (including empty sequence).

Example:
Input: s = "adceb", p = "*a*b"
Output: true
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = 1;
        
        for (int k = 1; k <= n; k++) {
            dp[k][0] = 0;
        }
    
        for (int k = 1; k <= m; k++) {
            bool flag = true;
            for (int a = 1; a <= k; a++) {
                if (p[a-1] != '*') {
                    flag = false;
                }
            }
            dp[0][k] = flag;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } 
                else if (p[j-1] == '*') {
                    bool case1 = dp[i-1][j];
                    bool case2 = dp[i][j-1];
                    if (case1 || case2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                } 
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution sol;

    string s1 = "aa", p1 = "a";
    cout << "Test 1 -> " << (sol.isMatch(s1, p1) ? "true ✅" : "false ❌") << endl;

    string s2 = "adceb", p2 = "*a*b";
    cout << "Test 2 -> " << (sol.isMatch(s2, p2) ? "true ✅" : "false ❌") << endl;

    string s3 = "acdcb", p3 = "a*c?b";
    cout << "Test 3 -> " << (sol.isMatch(s3, p3) ? "true ✅" : "false ❌") << endl;

    string s4 = "", p4 = "*";
    cout << "Test 4 -> " << (sol.isMatch(s4, p4) ? "true ✅" : "false ❌") << endl;

    return 0;
}
