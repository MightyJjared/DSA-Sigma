#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation
/*
🔹 LeetCode Reference: 123. Best Time to Buy and Sell Stock III
🔹 Problem Explanation:
You can complete at most two transactions (a buy followed by a sell).
Find the maximum profit possible using dynamic programming (tabulation approach).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); // dp[index][buy][count]

        // Base case 1: when no transactions left (count == 0)
        for (int index = 0; index <= n; index++) {
            for (int buy = 0; buy <= 1; buy++) {
                dp[index][buy][0] = 0;
            }
        }

        // Base case 2: when we reach end of array (index == n)
        for (int buy = 0; buy <= 1; buy++) {
            for (int count = 0; count <= 2; count++) {
                dp[n][buy][count] = 0;
            }
        }

        // Bottom-up tabulation
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int count = 1; count <= 2; count++) {
                    int profit = 0;
                    if (buy == 1) { // we can buy
                        profit = max(-prices[index] + dp[index + 1][0][count],  // buy
                                     0 + dp[index + 1][1][count]);              // skip
                    } else { // we can sell
                        profit = max(prices[index] + dp[index + 1][1][count - 1],  // sell
                                     0 + dp[index + 1][0][count]);               // skip
                    }
                    dp[index][buy][count] = profit;
                }
            }
        }

        return dp[0][1][2]; // start from index 0, allowed to buy, with 2 transactions
    }
};

int main() {
    Solution s;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(prices) << endl; // Expected output: 6
    return 0;
}
