#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation (on vs code just use double it will accept)
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
    int numDistinct(string s, string t) {
        int a = s.size();
        int b = t.size();

        vector<vector<int>> dp(a+1, vector<int> (b+1, 0));

        for(int i = 0; i <= a; i++){ // base case 1
            dp[i][0] = 1;
        }
        for(int j = 1; j <= b; j++){ // base case 2
            dp[0][j] = 0;
        }

        for(int i = 1; i <= a; i++){
            for(int j =1; j <= b; j++){
                if (s[i-1] == t[j-1]) {  // match case: pick or not pick
                int pick = dp[i - 1][j - 1];
                int notPick1 = dp[i - 1][j];
                dp[i][j] = pick + notPick1;
            }
            else{
                // else case: 
                dp[i][j] = dp[i - 1][j];
            }
            }
        }
        return dp[a][b];
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