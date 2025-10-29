#include <iostream>
#include <vector>
using namespace std;

// tabulation
/*
here inside the nested loop we have copy pasted and did one additional change ie in dp[][prev] we have done 
dp[][prev+1] as we cant store -1 index in array
also in the nested loop the 2 loop is going backwards ie from index-1 to -1 we can do reevrse also ie from -1
index-1 and chnage nothing else inside or outside it and it will still work
// also in base case since we are returning 0and here the dp is initialized as 0 no need to write the basecase
*/
/*
🔹 LeetCode Reference: 300. Longest Increasing Subsequence
🔹 Problem Explanation:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int prev = index - 1; prev >= -1; prev--) {
                int not_pick = dp[index + 1][prev + 1];
                int pick = -1e9;
                if (prev == -1 || nums[index] > nums[prev]) {
                    pick = 1 + dp[index + 1][index + 1];
                }
                dp[index][prev + 1] = max(pick, not_pick);
            }
        }
        return dp[0][-1+1]; // corresponds to prev = -1
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; // Example input
    cout << sol.lengthOfLIS(nums) << endl; // Expected output: 4
    return 0;
}
