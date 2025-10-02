#include <iostream>
#include <vector>
using namespace std;

// Memoization (Top-down DP)
// LeetCode 198: House Robber
// Question: You are given an array nums where each element represents money in a house. 
// You cannot rob two adjacent houses. Return the maximum amount you can rob.
// Logic: Use recursion + memoization. At each house index n, you have two options:
//   1. Pick the house -> add nums[n] + helper(n-2)
//   2. Skip the house -> helper(n-1)
// Store results in dp[n] to avoid recomputation.
// Example: nums = {2,7,9,3,1} -> Maximum amount = 12 (rob houses 1,3,5 => 2+9+1)

class Solution {
public:
    int helper(int n, vector<int> &nums, vector<int> &dp){
        if(n == 0){
            return nums[n];
        }
        if(n < 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int pick = helper(n-2, nums, dp) + nums[n];
        int notPick = helper(n-1, nums, dp);

        dp[n] = max(pick, notPick);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n-1, nums, dp);
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    Solution sol;
    cout << sol.rob(nums) << endl; 
    return 0;
}
