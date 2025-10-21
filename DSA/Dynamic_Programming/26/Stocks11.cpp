#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation space optimized
// LeetCode Reference: 309. Best Time to Buy and Sell Stock with Cooldown
// Problem Explanation:
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You may complete as many transactions as you like, but after you sell a stock, you cannot buy on the next day (cooldown = 1 day).
// Find the maximum profit you can achieve.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead1(2, 0);
        vector<int> ahead(2, 0);
        vector<int> current(2, 0);

        ahead[0] = ahead[1] = 0;

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0; 
                if(buy == 1){ // we can only buy
                    profit = max(-prices[index] + ahead[0], // take
                                 0 + ahead[1]);          // not take
                }
                else{ // we can only sell
                    profit = max(prices[index] + ahead1[1], // take
                                 0 + ahead[0]);          // not take
                }
                current[buy] = profit;
            }
            ahead1 = ahead;
            ahead = current;
        }
        return ahead[1]; // start at day 0 with buy permission
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2}; // example input from LeetCode 309
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Expected output: 3
    return 0;
}
