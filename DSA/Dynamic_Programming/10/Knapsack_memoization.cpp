#include <iostream>
#include <vector>
using namespace std;

/*
    0-1 Knapsack Problem (Memoization Approach)
    ------------------------------------------
    Question:
    You are given 'n' items, each with a value (val[i]) and a weight (wt[i]).
    You also have a knapsack (bag) with maximum capacity 'W'.
    The task is to maximize the total value of items that can be placed
    inside the knapsack without exceeding its weight capacity.
    Each item can either be included (1) or excluded (0), hence the name "0-1 Knapsack".

    Logic (Recursive + Memoization):
    - If no items are left (n == 0) or capacity is 0 (W == 0), return 0 (base cases).
    - If the result for (n, W) is already computed in dp[n][W], return it directly (to avoid recomputation).
    - Otherwise:
        * If the weight of the current item (wt[n-1]) is <= W, we have 2 choices:
              1. Include the item:
                     value = val[n-1] + knapsack(W - wt[n-1], n-1, ...)
              2. Exclude the item:
                     value = knapsack(W, n-1, ...)
           Take the maximum of these two.
        * If the weight of the current item > W, we cannot include it,
          so only the "exclude" choice is possible.
    - Store the result in dp[n][W] before returning (memoization).
*/

// Recursive function for 0-1 Knapsack
int knapsack(int W, int n, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
    // Base case 1: no items left
    if (n == 0) {
        return 0;
    }
    // Base case 2: no capacity left
    if (W == 0) {
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(wt[n-1] <= W){
        // include
        int ans1 = knapsack(W-wt[n-1],n-1, wt, val, dp) + val[n-1];
        
        //exclude
        int ans2 = knapsack(W, n-1, wt, val, dp);

        dp[n][W] = max(ans1, ans2);
        return dp[n][W];
    }
    else{
        dp[n][W] = knapsack(W, n-1, wt, val, dp);
        return dp[n][W];
    }

}

int main() {
    // Example items
    vector<int> val = {60, 100, 120};   // values of items
    vector<int> wt  = {1, 2, 3};     // weights of items
    int W = 5;                         // maximum capacity of knapsack
    int n = val.size();                 // number of items
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    cout << "Maximum value in Knapsack = " << knapsack(W, n, wt, val, dp) << endl;
    for(int i = 0; i < n+1; i++){
        for(int j=0; j < W+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
