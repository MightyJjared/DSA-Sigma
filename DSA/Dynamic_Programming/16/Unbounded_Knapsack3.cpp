#include <iostream>
#include <vector>
using namespace std;

// tabulation
// 🔹 LeetCode Reference: Similar to "Coin Change II" (Unbounded Knapsack pattern)
// 🔹 Problem Explanation:
// In Unbounded Knapsack, each item can be chosen multiple times.
// You are given 'n' items with their weights[] and values[] and a capacity 'W'.
// Find the maximum total value you can obtain without exceeding the capacity.

class Solution {
public:
    int unboundedKnapsack(int n, int W, vector<int> &wt, vector<int> &val) {
        vector<vector<int>> dp(n, vector<int> (W+1, 0));
        
        for(int i = wt[0]; i <= W; i++){
            int x = i / wt[0];
            dp[0][i] = x * val[0]; 
        }

        for(int i = 1; i < n; i++){
            for(int k = 0; k <= W; k++){
                int notPick = dp[i-1][k];

                int pick = -1e9;
                if(wt[i] <= k){
                    pick = val[i] + dp[i][k - wt[i]];
                }

                dp[i][k] = max(pick, notPick);
            }
        }
        return dp[n-1][W];
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
