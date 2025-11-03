#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoization
/*
🔹 LeetCode Reference: 312. Burst Balloons
---------------------------------------------------------
You are given n balloons, each with a number on it.
You may burst them in any order. When you burst balloon i,
you gain nums[i-1] * nums[i] * nums[i+1] coins.
Return the maximum coins you can collect.
*/

class Solution {
public:
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(i > j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int maximum = -1e9;
        for(int k = i; k <= j; k++) {
            int steps = nums[i-1] * nums[k] * nums[j+1]
                        + helper(i, k-1, nums, dp)
                        + helper(k+1, j, nums, dp);
            
            maximum = max(maximum, steps);
        }
        return dp[i][j] = maximum;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(1, n, nums, dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 5, 8};

    cout << "Maximum coins: " << sol.maxCoins(nums) << endl;

    return 0;
}
