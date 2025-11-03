#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// memoization
/*
🔹 LeetCode Reference: 132. Palindrome Partitioning II
-------------------------------------------------------
🧩 Problem:
Given a string `s`, partition it so that every substring is a palindrome.
Return the minimum number of cuts needed to make all substrings palindromes.

🧠 Example:
Input:  s = "aab"
Output: 1

Explanation:
We can split as "aa | b" → both are palindromes.
Hence, only one cut is required.
*/

class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int helper(int i, string &s, int n, vector<int> &dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int minimum = 1e9 / 2;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cuts = 1 + helper(j + 1, s, n, dp);
                minimum = min(minimum, cuts);
            }
        }
        return dp[i] = minimum;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, s, n, dp) - 1;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << "Minimum cuts: " << sol.minCut(s) << endl;
    return 0;
}
