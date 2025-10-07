#include <iostream>
#include <vector>
using namespace std;

// memoization
class Solution {
public:
    bool helper(int index, int k, vector<int>& nums, vector<vector<int>> &dp){
        if(k == 0){
            return true;
        }
        if(index == 0){
            if(nums[0] == k){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[index][k] != -1){
            return dp[index][k];
        }

        bool not_pick = helper(index-1, k, nums, dp);

        bool pick = false;
        if(nums[index] <= k){
            pick = helper(index-1, k-nums[index], nums, dp);
        }

        if(pick == true || not_pick == true){
            return dp[index][k] = true;
        }
        else{
            return dp[index][k] =false;
        }

    }

    bool subsetSum(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(n-1, target, nums, dp);
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
