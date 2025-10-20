#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// revcursive
/*
    🔹 LeetCode Problem: 44. Wildcard Matching
    -----------------------------------------
    🧩 Problem Statement:
    Given two strings `s` (the text) and `p` (the pattern), implement wildcard pattern matching 
    with support for '?' and '*' where:
        - '?' Matches any single character.
        - '*' Matches any sequence of characters (including the empty sequence).

    The matching should cover the entire input string (not partial).

    Example 1:
        Input: s = "aa", p = "a"
        Output: false
        Explanation: "a" does not match the entire string "aa".

    Example 2:
        Input: s = "aa", p = "*"
        Output: true
        Explanation: '*' matches any sequence of characters.

    Example 3:
        Input: s = "cb", p = "?a"
        Output: false

    🔸 Approach:
    - Recursion from the end of both strings.
    - Handle three cases:
        1️⃣ Direct character match or '?'
        2️⃣ '*' matches either zero characters (move j-1) or one character (move i-1)
        3️⃣ Base cases for pattern and string boundaries.

    ⚙️ Time Complexity (Recursive): Exponential
       (Can be optimized with Memoization or DP)

    ✅ LeetCode Reference: https://leetcode.com/problems/wildcard-matching/
*/

class Solution {
public:
    bool helper(int i, int j, string &s, string &p) {
        if (j < 0 && i < 0) {
            return true;
        }
        if (j < 0 && i >= 0) {
            return false;
        }
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?') {
            return helper(i - 1, j - 1, s, p);
        }

        else if (p[j] == '*') {
            bool case1 = helper(i - 1, j, s, p);
            bool case2 = helper(i, j - 1, s, p);
            if (case1 == true || case2 == true) {
                return true;
            } else {
                return false;
            }
        }

        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return helper(n - 1, m - 1, s, p);
    }
};

int main() {
    Solution sol;

    // 🔸 Example test cases
    string s = "aa";
    string p = "*";

    if (sol.isMatch(s, p)) {
        cout << "Pattern matches the string ✅" << endl;
    } else {
        cout << "Pattern does NOT match ❌" << endl;
    }

    return 0;
}
