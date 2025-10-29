#include <iostream>
#include <vector>
using namespace std;

// tabulation spce optimized
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
        int prev = -1;
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int index = n-1; index >=0; index--){
            for(int prev = index-1; prev >= -1; prev--){
                int not_pick = next[prev+1];
                int pick = -1e9;
                if(prev == -1 || nums[index] > nums[prev]){
                    pick = 1 + next[index+1];
                }
                curr[prev+1] = max(pick, not_pick);
            }
            next = curr;
        }
        return next[-1+1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; // Example input
    cout << sol.lengthOfLIS(nums) << endl; // Expected output: 4
    return 0;
}
