// memoization
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (n == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            } else {
                return 1e9;
            }
        }

        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }

        int not_pick = helper(n - 1, amount, coins, dp);
        int pick = 1e9;
        if (coins[n] <= amount) {
            pick = 1 + helper(n, amount - coins[n], coins, dp);
        }
        dp[n][amount] = min(pick, not_pick);
        return dp[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);

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
