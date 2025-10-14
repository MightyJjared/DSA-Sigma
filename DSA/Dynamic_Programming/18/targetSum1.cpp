#include <iostream>
#include <vector>
using namespace std;

/*
this is strive dp 21 the logic here is simple it is exactly ditto copy of countPartionin with difference problem
which we did earlier, to see how it is same form it see strivers video it is only 9 min
*/
/*
LeetCode Reference: 494. Target Sum
Question Explanation:
You are given an array of non-negative integers 'nums' and an integer 'target'.
You need to count the number of ways to assign '+' and '-' signs to each element
so that the resulting sum equals the target. This is equivalent to partitioning
the array into two subsets S1 and S2 such that sum(S1) - sum(S2) = target.
*/

class Solution {
public:
    void helper(int n , int sum, vector<int>& nums, vector<vector<int>> &dp){
        // base case 1
        if(nums[0] == 0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }
        // base cases 2
        if(nums[0] <= sum){
            if(nums[0] != 0){
                dp[0][nums[0]] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            for(int k = 0; k <= sum; k++){

                int not_pick = dp[i-1][k];

                int pick = 0;
                if(nums[i] <= k){
                    pick = dp[i-1][k- nums[i]];
                }

                dp[i][k] = pick + not_pick;
            }
        }
    } 
    int CountPartition(vector<int>& nums, int difference) {
        int n = nums.size();
        int totalsum = 0;

        for(int i =0; i <n; i++){
            totalsum += nums[i];
        }

        vector<vector<int>> dp(n, vector<int> (totalsum+1, 0));
        helper(n, totalsum, nums, dp);

        if((totalsum - difference) < 0){ // base case
            return false;
        }

        if((totalsum - difference) % 2 == 1){ // base case (cant be odd)
            return false;
        }

        int s1 = (totalsum-difference) / 2;
        
        // SAFETY CHECK: s1 must not exceed totalsum
        if (s1 > totalsum) {
            return 0;
        }
        return dp[n-1][s1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return CountPartition(nums, target);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 3};
    int target = 1;

    cout << "Number of ways to reach target " << target << " = " 
         << sol.findTargetSumWays(nums, target) << endl;

    return 0;
}
