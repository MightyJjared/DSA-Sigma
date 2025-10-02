#include <iostream>
#include <vector>
using namespace std;

// LeetCode 198: House Robber
// Question: You are given an array nums where each element represents money in a house. 
// You cannot rob two adjacent houses. Return the maximum amount you can rob.
// Logic: At each house, you have 2 choices -> rob it (and add nums[n] + result from n-2) 
// or skip it (result from n-1). Take the maximum of these two choices.
// Example: nums = {2,7,9,3,1} -> Best is rob house1(7) + house3(3) + house5(1) = 11 
// OR house1(7) + house3(9) = 16 (invalid since adjacent), so correct answer = 12 (2 + 9 + 1).

class Solution {
public:
    int helper(int n, vector<int> &nums){
        if(n == 0){
            return nums[n];
        }
        if(n < 0){
            return 0;
        }

        // pick case
        int pick = helper(n-2, nums) + nums[n];

        // not pick case
        int not_pick = helper(n-1,nums);
        
        return max(pick, not_pick);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return helper(n-1, nums);
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    Solution sol;
    cout << sol.rob(nums) << endl; 
    return 0;
}
