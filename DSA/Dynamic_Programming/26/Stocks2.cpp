#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursive (we are starting from index 0 and going till n)
/*
🔹 LeetCode 122: Best Time to Buy and Sell Stock II
---------------------------------------------------
🧩 Problem:
You are given an array `prices` where `prices[i]` is the price of a stock on the i-th day.
You can buy and sell the stock multiple times (but must sell before buying again).
Find the maximum profit you can achieve.

💡 Idea:
- Use recursion (or DP) with two states:
    ▪ `index`: current day
    ▪ `buy`: whether we can buy (1) or sell (0)
- At each step, we either:
    - Buy or skip (if we can buy)
    - Sell or skip (if we can sell)
- The recursion explores both choices and takes the maximum profit.

*/

class Solution {
public:
    int helper(int index, int buy, vector<int>& prices, int n) {
        if (index == n) {
            return 0;
        }

        int profit = 0;
        if (buy == 1) { // we can only buy
            profit = max(-prices[index] + helper(index + 1, 0, prices, n),  // take (buy)
                         0 + helper(index + 1, 1, prices, n));             // not take (skip)
        } else { // we can only sell
            profit = max(prices[index] + helper(index + 1, 1, prices, n),   // take (sell)
                         0 + helper(index + 1, 0, prices, n));             // not take (skip)
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return helper(0, 1, prices, n); // start with buy = 1 (we can buy first)
    }
};

int main() {
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};  // Example input
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Maximum Profit: " << sol.maxProfit(prices2) << endl;

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Maximum Profit: " << sol.maxProfit(prices3) << endl;

    return 0;
}
