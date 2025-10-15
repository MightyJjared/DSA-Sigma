#include <iostream>
#include <vector>
using namespace std;

// recursive
// approach - we have just mixed logic of count subset with sum equal and coin change 1
// basically we have chnaged 2 things , we copied everythin exact from count subset with sum equal then in that we
// changed the base when n==0 and copied the base of coin change 1 when n==0 and also in pick option, we have writen
// n instead of n-1 because we can choose a coin multiple times
/*
LeetCode Reference: 518. Coin Change II
Question Explanation:
You are given an integer 'amount' and an array 'coins' representing different coin denominations.
You need to find the total number of combinations that make up that amount.
Each coin can be used an unlimited number of times.

Example:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: There are four ways to make up amount 5:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

class Solution {
public:
    int helper(int n, int sum, vector<int> &nums){
        if(sum == 0){ // base case1 ( This base case is optional it doesnt change answer)
            return 1;
        }
        if (n == 0) { // base case 2
            if (sum % nums[0] == 0) {
                return 1;
            } else {
                return 0;
            }
        }



        int not_pick = helper(n-1, sum, nums);

        int pick = 0;
        if(nums[n] <= sum){
            pick = helper(n, sum-nums[n], nums);
        }

        return pick + not_pick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return helper(n-1, amount, coins);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Number of combinations to make amount " << amount << " = "
         << sol.change(amount, coins) << endl;

    return 0;
}
