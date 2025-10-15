#include <iostream>
#include <vector>
using namespace std;

// tabulation
// this is passing all cases in leetcode but at submition it is causing run time error 
class Solution {
public:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>> &dp){
        for(int i = 0; i <= index; i++){ // base case1 ( This base case is optional it doesnt change answer)
            dp[i][0] = 1;
        }
        
        for(int k = 0; k <= amount; k++){ // 2 base case
            if(k % coins[0] == 0){
                dp[0][k] = 1;
            }
        }
        
        for(int i = 1; i <= index; i++){
            for(int k = 0; k <= amount; k++){
                int not_pick = dp[i-1][k];

                int pick = 0;
                if(coins[i] <= k){
                    pick = dp[i][k - coins[i]];
                }

                dp[i][k] = pick + not_pick;
            }
        }
        return dp[index][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        return helper(n - 1, amount, coins, dp);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << sol.change(amount, coins) << endl;
    return 0;
}
