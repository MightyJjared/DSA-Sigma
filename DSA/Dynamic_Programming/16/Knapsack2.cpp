#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// memoization
/*
    0-1 Knapsack Problem (Memoization Approach)
    ------------------------------------------
    Question:
    You are given 'n' items, each with a value (val[i]) and a weight (wt[i]).
    You also have a knapsack (bag) with maximum capacity 'W'.
    The task is to maximize the total value of items that can be placed
    inside the knapsack without exceeding its weight capacity.
    Each item can either be included (1) or excluded (0), hence the name "0-1 Knapsack".
*/


int knapsack(int n, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
    if(n == 0){
        if(wt[n] <= W){
            return val[n];
        }
        return 0;
    }
    if(dp[n][W] != -1){
        return dp[n][W];
    }

    int not_pick = 0 + knapsack(n-1, W, wt, val, dp);

    int pick = INT_MIN;
    if(wt[n] <= W){
        pick = val[n] + knapsack(n-1, W - wt[n], wt, val, dp);
    }

    dp[n][W] = max(pick, not_pick);
    return dp[n][W];
}

int main() {
    
    vector<int> val = {60, 100, 120};   
    vector<int> wt  = {1, 2, 3};     
    int W = 5;                        
    int n = val.size();                 
    vector<vector<int>> dp(n, vector<int>(W+1, -1));

    cout << "Maximum value in Knapsack = " << knapsack(n-1, W, wt, val, dp) << endl;

    return 0;
}
