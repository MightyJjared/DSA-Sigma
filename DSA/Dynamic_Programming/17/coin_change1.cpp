#include <iostream>
#include <vector>
using namespace std;

// recursive
/*
here in pick instead of passing n-1 at index we are passing n, because we want to pick the maximum amount of coin
 present
*/
/*
📌 LeetCode Problem Reference: 322. Coin Change
https://leetcode.com/problems/coin-change/

Problem:
- You are given an integer array 'coins' representing different denominations of coins.
- You are also given an integer 'amount' representing a total amount of money.
- You need to compute the minimum number of coins needed to make up that amount.
- You have an **infinite supply** of each coin denomination.
- If the amount cannot be made up by any combination of the coins, return -1.

Example:
coins = [1, 2, 5], amount = 11

Steps:
- One optimal way: 5 + 5 + 1 = 11
- Minimum number of coins = 3
*/

class Solution {
public:
    int helper(int n, int amount, vector<int>& coins) {
        if (n == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }

        int not_pick = helper(n - 1, amount, coins);
        int pick = 1e9;
        if (coins[n] <= amount) {
            pick = 1 + helper(n, amount - coins[n], coins);
        }
        return min(pick, not_pick); 
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = helper(n - 1, amount, coins);

        if (ans == 1e9) {
            return -1;
        } else {
            return ans;
        }
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins = " << sol.coinChange(coins, amount) << endl;
    return 0;
}
