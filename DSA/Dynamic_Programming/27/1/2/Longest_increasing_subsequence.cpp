#include <iostream>
#include <vector>
using namespace std;

// this is the non intiutive approach striver gave because through this we can easily print the sequence and also
// it helps in solving different problems (striver dp 42)
/*
🔹 LeetCode Reference: 300. Longest Increasing Subsequence
🔹 Problem Explanation:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101].
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maximum = 1;
        for(int i =0; i <n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                }
            }
            maximum = max(maximum, dp[i]);
        }

        return maximum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; // Example input
    cout << "Length = " << sol.lengthOfLIS(nums) << endl; // Expected output: 4
    return 0;
}
