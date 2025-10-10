#include <iostream>
#include <vector>
using namespace std;

// tabulation
class Solution {
public:
    bool subsetSum(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        
        // base case convert both cases as it is from memoization
        for(int i =0; i< n; i++){ // 1 base case
            dp[i][0] = true;
        }

        if(nums[0] <= target){ // 2 base case
            dp[0][nums[0]] = true;
        } 

        // body
        for(int index =1; index <n; index++){ // 2 for loops because 2 variable ie index, target
            for(int k = 0; k < target+1; k++){
                
                bool not_pick = dp[index-1][k];  // this is completley copy past from memoization till end of loop

                bool pick = false;
                if(nums[index] <= k){
                    pick = dp[index-1][k-nums[index]];
                }

                if(pick == true || not_pick == true){
                    dp[index][k] = true;
                }
                else{
                    dp[index][k] =false;
                }
            }
        }
        return dp[n-1][target];
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