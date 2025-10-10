#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// This is from striver dp plalist video 16
// this is not accepted at leetcode because in that vriation negative are also included,
// but striver showed this for only positive 
// logic is we are writing the helper function which is copied from subset sum equal target tabulation form
// rest is easy to understand see video to help
/*
LeetCode Reference: #2035 – Partition Array Into Two Arrays to Minimize Sum Difference

Question:
You are given an integer array nums. Partition it into two subsets such that 
the absolute difference of their sums is minimized. 

Return the minimum possible difference.

Example:
Input: nums = [1,2,3,9]
Output: 3
Explanation: 
Subset1 = [1,2,3], sum = 6
Subset2 = [9], sum = 9
Absolute difference = |6 - 9| = 3
*/

class Solution {
public:
    // Helper function to build the DP table for subset sums
    void helper(int n, int target, vector<int>& nums, vector<vector<bool>>& dp) {
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;  // sum = 0 is always possible (by taking no elements)
        }

        if (nums[0] <= target) {
            dp[0][nums[0]] = true; // initialize with first element
        }

        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= target; k++) {
                bool not_pick = dp[i - 1][k];
                bool pick = false;
                if (nums[i] <= k) {
                    pick = dp[i - 1][k - nums[i]];
                }
                dp[i][k] = pick || not_pick;
            }
        }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // dp[i][k] = true if subset from first i elements can make sum = k
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
        helper(n, totalSum, nums, dp);

        int minimum = 1e9;
        // Try all possible subset sums
        for (int s1 = 0; s1 <= totalSum; s1++) {
            if (dp[n - 1][s1]) {
                int s2 = totalSum - s1;
                minimum = min(minimum, abs(s1 - s2));
            }
        }
        return minimum;
    }
};

// Example driver code
int main() {
    vector<int> nums = {1, 2, 3, 9};
    Solution sol;

    cout << "Minimum difference = " << sol.minimumDifference(nums) << endl;
    return 0;
}
