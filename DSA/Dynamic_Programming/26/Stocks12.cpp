#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabuation (space optimized)
// This is just copy paste from Stocks5 and acc to question we just substracted the fee when selling in take case
// just this one change and everything is same

// LeetCode Reference: 714. Best Time to Buy and Sell Stock with Transaction Fee
// Optimized tabulation using space compression. 
// We maintain two states: buy=1 (we can buy), buy=0 (we can sell). 
// Profit is updated day by day considering taking or skipping the transaction, 
// and subtracting the fee when selling.

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
                    profit = max(prices[index] + ahead[1] - fee , // take
                                 0 + ahead[0]);                // not take
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
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Maximum Profit = " << sol.maxProfit(prices, fee) << endl;
    return 0;
}
