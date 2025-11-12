#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// we copied the exact code of longest_increaing _subsequence(printing) and did 2 changes first before doing any
// operations on nums we are sorting(ascending order) it for our condition to work, and inside the nested loop
// we are changing the nums[prev] < nums[i] to nums[i] % nums[prev] == 0 as here we are not finding largets
// increasing subsequuence rather largest divisible subset
/*
🔹 LeetCode Reference: 368. Largest Divisible Subset
🔹 Problem Explanation:
Given a set of distinct positive integers nums, return the largest subset such that 
for every pair (Si, Sj) in the subset, either Si % Sj == 0 or Sj % Si == 0.

Example:
Input: nums = [1, 2, 4, 8]
Output: [1, 2, 4, 8]
Explanation: Every pair in this subset satisfies the divisibility condition.
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i++) hash[i] = i;

        int last_index = 0;
        int maximum = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maximum) {
                maximum = dp[i];
                last_index = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[last_index]);
        while (hash[last_index] != last_index) {
            last_index = hash[last_index];
            ans.push_back(nums[last_index]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 8};
    vector<int> res = sol.largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
