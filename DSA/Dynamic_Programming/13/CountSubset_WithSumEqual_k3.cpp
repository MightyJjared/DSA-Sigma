#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// tabulation
// Question: Count the number of subsets in the given array 'nums' whose sum equals 'target'.
// Example: nums = {1, 2, 3, 2, 1}, target = 5
// Possible subsets with sum 5: {2,3}, {3,2}, {1,2,2}, {2,3}, {1,3,1} etc. 
// So the function should return the total count of such subsets.

// Function to count subsets with sum = K

int countSubsetsWithSumK(vector<int> &nums, int sum){
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int> (sum+1, 0));
    for(int i =0; i < n; i++){
        dp[i][0] = 1; // 1 base case
    }
    if(nums[0] <= sum){
        dp[0][nums[0]] = 1;
    }

    for(int i =1; i<n; i++){
        for(int k =1; k < sum+1; k++){
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
    int n = 5, sum = 5;
    vector<int> nums = {1, 2, 3, 2, 1};

    int result = countSubsetsWithSumK(nums, sum);
    cout << "Count of subsets with sum " << sum << " = " << result << "\n";

    return 0;
}
