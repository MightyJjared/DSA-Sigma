#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// recursive
// Question: Count the number of subsets in the given array 'nums' whose sum equals 'target'.
// Example: nums = {1, 2, 3, 2, 1}, target = 5
// Possible subsets with sum 5: {2,3}, {3,2}, {1,2,2}, {2,3}, {1,3,1} etc. 
// So the function should return the total count of such subsets.

// Function to count subsets with sum = K
int helper(int n, int sum, vector<int> &nums){
    if(sum == 0){ // base case1
        return 1;
    }
    if(n == 0){ // base case 2
        if(nums[n] == sum){
            return 1;
        }
        else{
            return 0;
        }
    }

    int not_pick = helper(n-1, sum, nums);

    int pick = 0;
    if(nums[n] <= sum){
        pick = helper(n-1, sum-nums[n], nums);
    }

    return pick + not_pick;
}


int countSubsetsWithSumK(vector<int> &nums, int target){
    int sum = 5;
    int n = nums.size();
    return helper(n-1,sum,nums);
}

int main() {
    // Example input
    int n = 5, sum = 5;
    vector<int> nums = {1, 2, 3, 2, 1};

    int result = countSubsetsWithSumK(nums, sum);
    cout << "Count of subsets with sum " << sum << " = " << result << "\n";

    return 0;
}
