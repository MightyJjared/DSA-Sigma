#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation, this is exact copy of Stocks4 here just we have a cool down condition, so we just changes 2 things
// 1- when selling if we take it we are doing index+2 instead of index+1 because of 1 day cool down
// since we are writing index+2 therefore it shouldnt go out of bounds thats why we are declaring 2d vector as n+2 
// instead of n+1, everything else is exactly same

// LeetCode Reference: 309. Best Time to Buy and Sell Stock with Cooldown
// tabulation, this is exact copy of Stocks4 here just we have a cool down condition, so we just changes 2 things
// 1- when selling if we take it we are doing index+2 instead of index+1 because of 1 day cool down
// since we are writing index+2 therefore it shouldnt go out of bounds thats why we are declaring 2d vector as n+2 
// instead of n+1, everything else is exactly same

class Solution {
public:
    int maxProfit(vector<int>& prices) { // buy =1, sell = 0
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

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
                    profit = max(prices[index] + dp[index+2][1], // sell
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
