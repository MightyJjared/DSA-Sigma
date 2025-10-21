#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation
/*
🔹 LeetCode Reference: 122. Best Time to Buy and Sell Stock II
---------------------------------------------------------------
🧠 Problem:
Given an array prices where prices[i] is the price of a given stock on the ith day, 
you can buy and sell the stock multiple times. Find the maximum profit.
You cannot hold more than one stock at a time (must sell before buying again).

This implementation uses tabulation (bottom-up DP) approach.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) { // buy =1, sell = 0
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // Base case: on day n, profit is 0 regardless of buy/sell
        dp[n][0] = dp[n][1] = 0;

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0; 
                if(buy == 1){ // can buy
                    profit = max(-prices[index] + dp[index+1][0], // buy
                                 dp[index+1][1]);                 // skip
                }
                else{ // can sell
                    profit = max(prices[index] + dp[index+1][1], // sell
                                 dp[index+1][0]);                // skip
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1]; // start from day 0 with buy allowed
    }
};

int main() {
    Solution sol;

    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Maximum Profit = " << sol.maxProfit(prices) << endl;

    return 0;
}
