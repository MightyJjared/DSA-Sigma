#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// tabulation
class Solution {
public:
    int helper(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        for(int i =0; i<= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }

        for(int index = 1; index < n; index++){
            for(int k = 0; k <= amount; k++){
                int not_pick = dp[index - 1][k];
                int pick = 1e9;
                if (coins[index] <= k) {
                    pick = 1 + dp[index][k - coins[index]];
                }
                dp[index][k] = min(pick, not_pick);
            }
        }

        return dp[n-1][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        int ans = helper(n, amount, coins, dp);

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
