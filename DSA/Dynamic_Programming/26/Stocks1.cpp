#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
🔹 LeetCode Reference: 121. Best Time to Buy and Sell Stock
-------------------------------------------------
🧠 Problem:
You are given an array `prices` where prices[i] is the price of a stock on day i.
You want to maximize your profit by choosing a single day to buy and a different
day in the future to sell that stock.

Return the maximum profit you can achieve. If no profit is possible, return 0.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1), sell on day 5 (price = 6)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy = prices[0];
        int maxprofit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestbuy) {
                maxprofit = max(maxprofit, prices[i] - bestbuy);
            }
            bestbuy = min(bestbuy, prices[i]);
        }
        return maxprofit;
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit (Test 1): " << sol.maxProfit(prices1) << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit (Test 2): " << sol.maxProfit(prices2) << endl;

    vector<int> prices3 = {2, 4, 1};
    cout << "Max Profit (Test 3): " << sol.maxProfit(prices3) << endl;

    return 0;
}
