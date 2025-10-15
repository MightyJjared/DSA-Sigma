#include <iostream>
#include <vector>
using namespace std;

// memoization
// 🔹 LeetCode Reference: Similar to "Coin Change II" (Unbounded Knapsack pattern)
// 🔹 Problem Explanation:
// In Unbounded Knapsack, each item can be chosen multiple times.
// You are given 'n' items with their weights[] and values[] and a capacity 'W'.
// Find the maximum total value you can obtain without exceeding the capacity.

class Solution {
public:
    int helper(int index, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
        if(index == 0){
            if(wt[0] <= W){
                int x= W / wt[0];
                return x * val[0]; 
            }
            else{
                return 0;
            }
        }

        if(dp[index][W] != -1){
            return dp[index][W];
        }

        int notPick = helper(index-1, W, wt, val, dp);

        int pick = -1e9;
        if(wt[index] <= W){
            pick = val[index] + helper(index, W - wt[index], wt, val, dp);
        }

        return dp[index][W] = max(pick, notPick);
    }
    int unboundedKnapsack(int n, int W, vector<int> &wt, vector<int> &val) {
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return helper(n-1, W, wt, val, dp);
    }
};

int main() {
    Solution sol;

    // Example inputs (you can modify as needed)
    int n = 4;
    int W = 8;
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {10, 40, 50, 70};

    int result = sol.unboundedKnapsack(n, W, wt, val);
    cout << "Maximum value = " << result << endl;

    return 0;
}
