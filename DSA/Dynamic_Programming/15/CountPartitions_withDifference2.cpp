#include <iostream>
#include <cmath> // for pow
#include <vector>
using namespace std;

// in constraint it said answer might be too large that why we are using mod
// this is same as part1 but here we are using different formulaas explained down
/*
Question: Count Partitions With Given Difference (handling zeros)

Given an array 'nums' of non-negative integers (can include 0) and a target difference 'diff',
you need to find the number of ways to partition the array into two subsets
S1 and S2 such that:

    sum(S1) - sum(S2) = diff

Explanation:

1. Let totalSum = sum of all elements in nums.
2. Let sum(S1) = s1 and sum(S2) = s2
   Then:
       s1 - s2 = diff
       s1 + s2 = totalSum
   Adding both equations: 2*s1 = totalSum + diff
   => s1 = (totalSum + diff) / 2

3. The problem reduces to counting the number of subsets with sum = s1.

*/

class Solution {
public:
    int mod = int(1e9 + 7);
    void helper(vector<int> &nums, int sum, vector<vector<int>> &dp){
        int n = nums.size();

        if(nums[0] == 0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }
        if(nums[0] <= sum){
            if(nums[0] != 0){
                dp[0][nums[0]] = 1;
            }
        }

        for(int i =1; i<n; i++){
            for(int k =0; k <= sum; k++){
                int not_pick = dp[i-1][k];
                int pick = 0;
                if(nums[i] <= k){
                    pick = dp[i-1][k-nums[i]];
                }
                dp[i][k] = (pick + not_pick) % mod;
            }
        }
    }

    int countPartitionsWithDiff(vector<int> &nums, int diff) {
        int totalsum = 0;
        int n = nums.size();

        for(int i =0; i< n; i++){
            totalsum += nums[i];
        }
        
        vector<vector<int>> dp(n, vector<int> (totalsum+1, 0));
        helper(nums, totalsum, dp);

        if((totalsum + diff) % 2 == 1){ // base case 1 - it cant be odd number because we are dividig by 2
            return 0;
        }

        if(totalsum + diff < 0){
            return 0;
        }

        int s1 = (totalsum + diff) / 2;
        return dp[n-1][s1] % mod;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3};
    
    int diff = 1;

    Solution sol;
    int result = sol.countPartitionsWithDiff(nums, diff);
    cout << "Number of partitions with difference " << diff << " = " << result << "\n";

    return 0;
}
