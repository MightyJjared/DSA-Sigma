#include <iostream>
#include <vector>
using namespace std;

// tabulation + space optimization
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
    int rob(vector<int>& nums) {
        int n = nums.size();
       
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            //take
            int take = prev2 + nums[i];
            // not take
            int not_take = prev1;

            int current = max(take, not_take);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    Solution sol;
    cout << sol.rob(nums) << endl; 
    return 0;
}
