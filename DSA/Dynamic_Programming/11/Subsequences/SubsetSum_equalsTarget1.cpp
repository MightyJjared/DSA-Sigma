#include <iostream>
#include <vector>
using namespace std;

// recursive
/*
Problem: Subset Sum Equals Target

Given an array of integers 'nums' and an integer 'target', determine if there exists a subset
of 'nums' whose sum is exactly equal to 'target'.

Example:
Input: nums = {1, 2, 3, 7}, target = 6
Output: true  // Because the subset {1, 2, 3} sums to 6
*/

class Solution {
public:
    bool helper(int n, int target, vector<int>& nums){
        if(target == 0){
            return true;
        }
        if(n == 0){
            if(nums[0] == target){
                return true;
            }
            else{
                return false;
            }
        }

        bool not_pick = helper(n-1, target, nums);

        bool pick = false;
        if(nums[n] <= target){
            pick = helper(n-1, target-nums[n], nums);
        }

        if(pick == true || not_pick == true){
            return true;
        }
        else{
            return false;
        }

    }

    bool subsetSum(vector<int>& nums, int target){
        int n = nums.size();
        return helper(n-1, target, nums);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 7};
    int target = 6;

    Solution sol;
    if(sol.subsetSum(nums, target)) {
        cout << "Subset with sum " << target << " exists\n";
    } else {
        cout << "No subset with sum " << target << "\n";
    }
    return 0;
}
