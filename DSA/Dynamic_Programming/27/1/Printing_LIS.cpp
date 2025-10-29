#include <iostream>
#include <vector>
using namespace std;

// printing (we are not using meoization because in memoization if it has already computed an asnwer for cetain 
//function it will return that value and we wont have the chance to gets our desired sequence for printing)


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
    int helper(int index, int prev, vector<int>& nums, int n,
               vector<vector<int>> &dp, vector<int> &temp, vector<int> &ans) {
        if (index == n) {
            if (temp.size() > ans.size()) {
                ans = temp;
            }
            return 0;
        }

        // ⚠️ Don't return cached dp result — it prevents sequence building
        int not_pick = helper(index + 1, prev, nums, n, dp, temp, ans);

        int pick = -1e9;
        if (prev == -1 || nums[index] > nums[prev]) {
            temp.push_back(nums[index]);
            pick = 1 + helper(index + 1, index, nums, n, dp, temp, ans);
            temp.pop_back(); // backtrack
        }

        // Still store dp value for LIS length
        return dp[index][prev + 1] = max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> temp;
        vector<int> ans;

        int result = helper(0, prev, nums, n, dp, temp, ans);

        cout << "Sequence = ";
        for (auto itr : ans) cout << itr << " ";
        cout << endl;

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 6}; // Example input
    cout << "length = " << sol.lengthOfLIS(nums) << endl; // Expected output: 4
    return 0;
}
