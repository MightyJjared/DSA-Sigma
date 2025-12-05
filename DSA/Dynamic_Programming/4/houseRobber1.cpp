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


/*
IMPORTANT NOTE:
We CANNOT use `if (n == 1) return nums[1];` as a base case.
Why? Because for input nums = [2, 1], the correct answer is 2 (rob house 0),
but `return nums[1]` gives 1 → WRONG ANSWER.

Explanation:
In House Robber, when n == 1 (second house), the best choice is NOT always
to take nums[1]. We must compare BOTH options:
    - rob first house      → nums[0]
    - rob second house     → nums[1]
so the correct base case should be:
    if (n == 1) return max(nums[0], nums[1]);

This is why using `return nums[1]` is incorrect and fails cases like [2,1].
*/

class Solution {
public:
    int helper(int n, vector<int> &nums){
        if(n == 0){
            return nums[0];
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
