#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// tabulation


// Function to count subsets with sum = K

int countSubsetsWithSumK(vector<int> &nums, int sum){
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int> (sum+1, 0));
    if(nums[0] == 0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }
    if(nums[0] != 0){
        if(nums[0] <= sum){
            dp[0][nums[0]] = 1;
        }
    }

    for(int i =1; i<n; i++){
        for(int k =0; k < sum+1; k++){
            int not_pick = dp[i-1][k];

            int pick = 0;
            if(nums[i] <= k){
                pick = dp[i-1][k-nums[i]];
            }

            dp[i][k] = pick + not_pick;
        }
    }
    return dp[n-1][sum];    
}

int main() {
    // Example input
    int sum = 5;
    vector<int> nums = {1, 2, 3, 2, 1};

    int result = countSubsetsWithSumK(nums, sum);
    cout << "Count of subsets with sum " << sum << " = " << result << "\n";

    return 0;
}
