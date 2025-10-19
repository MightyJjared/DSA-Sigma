#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// memoization (1 base indexing for tabulation)
/*
🔹 LeetCode Reference: 115. Distinct Subsequences
-------------------------------------------------
🧠 Problem:
You are given two strings s and t.
Return the number of distinct subsequences of s which equals t.

A subsequence of a string is formed by deleting some (or none) characters 
without disturbing the relative positions of the remaining characters.

Example 1:
Input:  s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can get "rabbit" from "rabbbit":
rabbbit
rabbbit
rabbbit

Example 2:
Input:  s = "babgbag", t = "bag"
Output: 5
Explanation:
The 5 distinct subsequences are:
babgbag → bag
babgbag → bag
babgbag → bag
babgbag → bag
babgbag → bag
*/

class Solution {
public:
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j  == 0) {  // all characters of t are matched
            return 1;
        }
        if (i == 0) {  // s exhausted but t not matched
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if (s[i-1] == t[j-1]) {  // match case: pick or not pick
            int pick = helper(i - 1, j - 1, s, t, dp);
            int notPick1 = helper(i - 1, j, s, t, dp);
            return dp[i][j] = pick + notPick1;
        }

        // else case: skip s[i]
        return dp[i][j] = helper(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int i = s.size();
        int j = t.size();
        vector<vector<int>> dp(i+1, vector<int> (j+1, -1));
        return helper(i , j , s, t, dp);
    }
};

int main() {
    Solution sol;

    string s1 = "rabbbit";
    string t1 = "rabbit";
    cout << "Example 1:\nInput: s = " << s1 << ", t = " << t1
         << "\nOutput: " << sol.numDistinct(s1, t1) << "\n\n";

    string s2 = "babgbag";
    string t2 = "bag";
    cout << "Example 2:\nInput: s = " << s2 << ", t = " << t2
         << "\nOutput: " << sol.numDistinct(s2, t2) << "\n";

    return 0;
}