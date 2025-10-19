#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// recursive
/*
🔹 LeetCode Reference: 72. Edit Distance
-------------------------------------------------
🧠 Problem:
Given two strings word1 and word2, return the minimum number of operations required 
to convert word1 to word2. You can insert, delete, or replace a character.

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: horse -> rorse (replace 'h' with 'r')
             rorse -> rose  (remove 'r')
             rose  -> ros   (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
*/

class Solution {
public:
    int helper(int i, int j, string &word1, string &word2) {
        // Base case: word1 exhausted, insert remaining letters of word2
        if (i < 0) {
            return j + 1;
        }
        // Base case: word2 exhausted, delete remaining letters of word1
        if (j < 0) {
            return i + 1;
        }

        // Characters match, no operation needed
        if (word1[i] == word2[j]) {
            return helper(i - 1, j - 1, word1, word2);
        } 
        else {
            // Compute all three possible operations
            int insertOp = 1 + helper(i, j - 1, word1, word2);
            int deleteOp = 1 + helper(i - 1, j, word1, word2);
            int replaceOp = 1 + helper(i - 1, j - 1, word1, word2);

            return min(insertOp, min(deleteOp, replaceOp));
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return helper(n - 1, m - 1, word1, word2);
    }
};

int main() {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    cout << "Minimum operations to convert '" << word1 
         << "' to '" << word2 << "' = " 
         << sol.minDistance(word1, word2) << endl;

    return 0;
}
