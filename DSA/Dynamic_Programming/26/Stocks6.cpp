#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoization (3D)
/*
🔹 LeetCode 123: Best Time to Buy and Sell Stock III
🔹 Problem Explanation:
   - You may complete at most 2 transactions.
   - Each transaction = 1 buy + 1 sell.
   - You must sell before you buy again.
🔹 Approach:
   - Use recursion + memoization (top-down DP).
   - `count` tracks remaining transactions.
   - Only selling decreases `count` (since one transaction completes after a sell).
*/

class Solution {
public:
    int helper(int index, int buy, vector<int>& prices, int n,
               vector<vector<vector<int>>> &dp, int count) {

        // Base cases
        if (count == 0 || index == n) return 0;

        // Memoization check
        if (dp[index][buy][count] != -1)
            return dp[index][buy][count];

        int profit = 0;

        if (buy == 1) { // can buy
            profit = max(
                -prices[index] + helper(index + 1, 0, prices, n, dp, count), // buy
                 0 + helper(index + 1, 1, prices, n, dp, count)              // skip
            );
        } else { // can sell
            profit = max(
                 prices[index] + helper(index + 1, 1, prices, n, dp, count - 1), // sell
                 0 + helper(index + 1, 0, prices, n, dp, count)                  // skip
            );
        }

        return dp[index][buy][count] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int count = 2; // at most 2 transactions
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, prices, n, dp, count);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
