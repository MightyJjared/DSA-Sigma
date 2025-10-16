#include <iostream>
#include <vector>
using namespace std;

// recursive
/*
🔹 Problem: Longest Common Subsequence (Striver DP 25)
🔹 LeetCode Reference: 1143. Longest Common Subsequence

🧩 Problem Explanation:
You are given two strings, text1 and text2.
You need to find the **length of the longest subsequence** that is present in both strings.

A subsequence is a sequence that appears in the same order, 
but not necessarily contiguous.

Example:
-----------
text1 = "abcde"
text2 = "ace"

Common subsequences are:
"a", "ae", "ace"
Length of longest common subsequence = 3  ✅

Intuition:
-----------
- If characters at current indices match → take 1 + solve for remaining strings.
- If they don’t match → try both possibilities:
  1️⃣ Skip current character from text1
  2️⃣ Skip current character from text2
  and take the maximum result.

This is a **classic dynamic programming** problem (similar to edit distance).
*/

class Solution {
public:
    int helper(int i1, int i2, string &text1, string &text2){
        if(i1 < 0 || i2 < 0){
            return 0;
        }

        int match = -1e9;
        int not_match = -1e9;
        if(text1[i1] == text2[i2]){
             return match = 1  + helper(i1-1, i2-1, text1, text2);
        }
        
        // only executed if (characters don't match)
        int not_match1 = 0 + helper(i1-1, i2, text1, text2);
        int not_match2 = 0 + helper(i1, i2-1, text1, text2);
        return not_match = max(not_match1, not_match2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i1 = text1.size();
        int i2 = text2.size();
        return helper(i1-1, i2-1, text1, text2);
    }
};

int main() {
    Solution sol;

    // Example inputs (you can modify as needed)
    string text1 = "abcde";
    string text2 = "ace";

    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence = " << result << endl;

    return 0;
}
