#include <iostream>
#include <vector>
using namespace std;

// memoization
/*
LeetCode Reference: #416 – Partition Equal Subset Sum
*/

class Solution {
public:
    // Exact function for subset sum equals target
    bool helper(int n, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }

        if(n == 0){
            if(nums[0] == target){
                return true;
            } else {
                return false;
            }
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        bool not_pick = helper(n-1, target, nums,dp);

        bool pick = false;
        if(nums[n] <= target){
            pick = helper(n-1, target - nums[n], nums,dp);
        }

        return dp[n][target] = pick || not_pick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0){
            return false;
        }

        int target = sum / 2; // If a subset with half of total sum exists, the rest automatically forms the other half
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(n-1, target, nums, dp);
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};
    Solution sol;

    if(sol.canPartition(nums)){
        cout << "Array can be partitioned into two subsets with equal sum.\n";
    } else {
        cout << "Array cannot be partitioned into two subsets with equal sum.\n";
    }

    return 0;
}
