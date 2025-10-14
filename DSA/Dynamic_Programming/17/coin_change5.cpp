#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode Reference: 518. Coin Change II
Question Explanation:
You are given an integer 'amount' and an array 'coins' representing different coin denominations.
You need to find the total number of combinations that make up that amount.
Each coin can be used an unlimited number of times.

Example:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: There are four ways to make up amount 5:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

class Solution {
public:
    int helper(int n, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(sum == 0){ // base case1
            return 1;
        }
        if (n == 0) {
            if (sum % nums[0] == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        if(dp[n][sum] != -1){
            return dp[n][sum];
        }

        int not_pick = helper(n-1, sum, nums, dp);

        int pick = 0;
        if(nums[n] <= sum){
            pick = helper(n, sum-nums[n], nums, dp);
        }

        return dp[n][sum] = pick + not_pick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return helper(n-1, amount, coins, dp);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Number of combinations to make amount " << amount << " = "
         << sol.change(amount, coins) << endl;

    return 0;
}
