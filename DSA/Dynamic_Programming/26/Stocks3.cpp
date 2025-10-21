#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoization (we are starting from index 0 and going till n)
/*
🔹 LeetCode Reference: 122. Best Time to Buy and Sell Stock II
---------------------------------------------------------------
🧠 Problem:
Given an array prices where prices[i] is the price of a given stock on the ith day, 
you can buy and sell the stock multiple times. Find the maximum profit.
You cannot hold more than one stock at a time (must sell before buying again).

This implementation uses recursion with memoization (top-down DP).
*/

class Solution {
public:
    int helper(int index, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
        if(index == n){
            return 0; // no days left, no profit
        }

        if(dp[index][buy] != -1){
            return dp[index][buy]; // return memoized result
        }

        int profit = 0; 
        if(buy == 1){ // can buy
            profit = max(-prices[index] + helper(index+1, 0, prices, n, dp), // buy
                         0 + helper(index+1, 1, prices, n, dp));             // skip
        }
        else{ // can sell
            profit = max(prices[index] + helper(index+1, 1, prices, n, dp),  // sell
                         0 + helper(index+1, 0, prices, n, dp));            // skip
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // memoization table
        return helper(0, 1, prices, n, dp);            // start with buy = 1
    }
};

int main() {
    Solution sol;

    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Maximum Profit = " << sol.maxProfit(prices) << endl;

    return 0;
}
