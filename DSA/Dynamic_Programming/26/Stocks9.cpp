#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// this is tabulation and space optimized for leetcode 188 we just copied stocks8 code as it is and chnaged count = 2
// with k everything is same
/*
🔹 LeetCode Reference: 188. Best Time to Buy and Sell Stock IV
🔹 Problem Explanation:
   - You are given an integer k and an array of prices.
   - You can complete at most k transactions (buy + sell).
   - Goal: maximize total profit.
   - Approach: Dynamic Programming (space-optimized)
     - State: ahead[buy][count], current[buy][count]
     - buy = 1 → can buy, buy = 0 → can sell
     - count = remaining transactions allowed
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int count = k;
        vector<vector<int>> ahead(2, vector<int> (k+1, 0)); // tabulation table
        vector<vector<int>> current(2, vector<int> (k+1, 0));


        for(int index =n-1; index >= 0; index--){
            for(int buy =0; buy <= 1; buy++){
                for(int count = 1; count <= k; count++){
                    int profit = 0; 
                    if(buy == 1){ // can buy
                        profit = max(-prices[index] + ahead[0][count], // buy
                                    0 + ahead[1][count]);             // skip
                    }
                    else{ // can sell
                        profit = max(prices[index] + ahead[1][count-1],  // sell
                                    0 + ahead[0][count]);            // skip
                    }
                    current[buy][count] = profit;
                }
            }
            ahead = current;
        }
        return ahead[1][k];
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3,2,6,5,0,3}; // Example input
    int k = 2;                           // Maximum 2 transactions
    cout << "Max Profit: " << sol.maxProfit(k, prices) << endl; // Output
    return 0;
}