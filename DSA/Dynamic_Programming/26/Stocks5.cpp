#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulaion (space optimized, this is expected in interview)
/*
🔹 LeetCode Reference: 122. Best Time to Buy and Sell Stock II
---------------------------------------------------------------
🧠 Problem:
Given an array prices where prices[i] is the price of a given stock on the i-th day, 
find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).

Example:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 4.
             Buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 3.
             Total profit = 4 + 3 = 7
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
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
                    profit = max(prices[index] + ahead[1], // take
                                 0 + ahead[0]);          // not take
                }
                current[buy] = profit;
            }
            ahead = current;
        }
        return ahead[1]; // start at day 0 with buy permission
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit = " << sol.maxProfit(prices) << endl;
    return 0;
}
