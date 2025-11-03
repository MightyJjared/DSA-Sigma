#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//recursive
/*
important note - 1- from final answer we are substracting 1 because our for loop will add 1 and then reach n then
return 0 so thee is one extra cut happening
2 - refernce striver dp  53
*/
/*
🔹 LeetCode Reference: 132. Palindrome Partitioning II
-------------------------------------------------------
🧩 Problem:
Given a string `s`, partition `s` such that every substring of the 
partition is a palindrome. Return the minimum number of cuts needed 
for a palindrome partitioning of `s`.

🧠 Example:
Input:  s = "aab"
Output: 1

Explanation:
We can make one cut between "aa" and "b":
"a | ab" → "aa" and "b" are both palindromes.
Hence, only 1 cut is required.
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

    int helper(int i, string &s, int n) {
        if (i == n) {
            return 0;
        }

        int minimum = 1e9;
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                int cuts = 1 + helper(j + 1, s, n);
                minimum = min(minimum, cuts);
            }
        }
        return minimum;
    }

    int minCut(string s) {
        int n = s.size();
        return helper(0, s, n) - 1;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << "Minimum cuts: " << sol.minCut(s) << endl;
    return 0;
}
