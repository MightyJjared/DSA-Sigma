#include <iostream>
#include <vector>
using namespace std;

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
    int helper(int index, int prev, vector<int>& nums, int n){
        if(index == n){
            return 0;
        }
        int not_pick = helper(index+1, prev, nums, n);
        int pick = -1e9;
        if(prev == -1 || nums[index] > nums[prev]){
            pick = 1 + helper(index+1,index,nums, n);
        }
        return max(pick, not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        return helper(0, prev, nums, n);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18}; // Example input
    cout << sol.lengthOfLIS(nums); // Expected output: 4
    cout << endl;
    return 0;
}
