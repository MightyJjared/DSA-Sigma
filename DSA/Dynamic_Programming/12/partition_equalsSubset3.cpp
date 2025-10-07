#include <iostream>
#include <vector>
using namespace std;

// tabulation
/*
LeetCode Reference: #416 – Partition Equal Subset Sum
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0){
            return false;
        }

        int target = sum / 2; // If a subset with half of total sum exists, the rest automatically forms the other 
                              // half

        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));

        for(int i =0; i < n; i++){ // Exact function for subset sum equals target
            dp[i][0] = true;       // from tabulation till end.
        }

        if(nums[0] <= target){
            dp[0][nums[0]] = true;
        }
        
        for(int index =1; index <n; index++){
            for(int k =1; k <target+1; k++){
                bool not_pick = dp[index-1][k];

                bool pick = false;
                if(nums[index] <= k){
                    pick = dp[index-1][k - nums[index]];
                }

                dp[index][k] = pick || not_pick;
            }
        }
        return dp[n-1][target];
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};
    Solution sol;

    if(sol.canPartition(nums)){
        cout << "Array can be partitioned into two subsets with equal sum.\n";
    } else {
        cout << "Array cannot be partitioned into two subsets with equal sum.\n";
    }

    return 0;
}
