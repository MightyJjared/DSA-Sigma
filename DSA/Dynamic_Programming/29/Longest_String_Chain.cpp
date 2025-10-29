#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// same copied form longest increasing subsequence just sorted the nums before doing any operation based on size
// in ascending order, changed the condition inside the nested loops from nums[prev] < nums[i] to 
// (order(words[i], words[prev]) == true) where in order function we are checking if 2 strings are exactly same
// in order but the first string s1 is having one extra word as per question condition
/*
🔹 LeetCode Reference: 1048. Longest String Chain
🔹 Problem Explanation:
Given a list of words, you need to find the length of the longest possible word chain.

A word chain is formed such that each word in the chain is obtained by 
adding exactly one letter to the previous word.

Example:
Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One possible chain is "a" -> "ba" -> "bda" -> "bdca".
*/

class Solution {
public:
    static bool comp(string &s1, string &s2) { // sorting based on size (ascending order)
        return s1.size() < s2.size();
    }

    bool order(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) {
            return false;
        }

        int i = 0; // index for bigger string (s1)
        int j = 0; // index for smaller string (s2)

        while (i < s1.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        if (i == s1.size() && j == s2.size()) {
            return true;
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);

        int maximum = 1;
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if ((order(words[i], words[prev]) == true) && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }
};

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    Solution sol;
    cout << "Longest String Chain Length: " << sol.longestStrChain(words) << endl;
    return 0;
}