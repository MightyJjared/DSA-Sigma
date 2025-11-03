#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// tabulation
// here we cannot space optimized this furter , if we do it it will increase time complexity
/*
🔹 LeetCode 132: Palindrome Partitioning II
--------------------------------------------
🧩 Problem:
Given a string s, partition s such that every substring is a palindrome. 
Return the minimum number of cuts needed for a palindrome partitioning of s.

💡 Example:
Input: s = "aab"
Output: 1
Explanation: 
The palindrome partitioning is ["aa","b"] → only 1 cut is needed.

🧠 Approach (Tabulation - Bottom Up):
- dp[i] → stores the minimum cuts required for substring starting from index i.
- For every i (from n-1 → 0):
    - Try all possible j (from i → n-1)
    - If substring s[i..j] is a palindrome → 
      cuts = 1 + dp[j+1]
    - Take the minimum among all such partitions.
- Final answer = dp[0] - 1 (since last partition doesn’t need an extra cut)
*/

class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--) {
            int minimum = 1e9/2;
            for(int j = i; j < n; j++) {
                if(isPalindrome(i, j, s)) {
                    int cuts = 1 + dp[j+1];
                    minimum = min(minimum, cuts);
                }
            }
            dp[i] = minimum;
        }

        return dp[0] - 1;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << sol.minCut(s) << endl;
    return 0;
}
