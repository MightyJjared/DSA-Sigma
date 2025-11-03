#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation
// here we did 2 changes first initialzed vector as n+2 instead of n+1 like memoization
// second in inner loop we initialized j with i instead of 1 as think logically j will always be greater or equal
// to 1
// LeetCode 312: Burst Balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                int maximum = -1e9;
                for(int k = i; k<= j; k++){
                    int steps = nums[i-1] * nums[k] * nums[j+1]
                                + dp[i][k-1]
                                + dp[k+1][j];
                    
                    maximum = max(maximum, steps);
                }
                dp[i][j] = maximum;
            }
        }
        return dp[1][n];
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;
    return 0;
}
