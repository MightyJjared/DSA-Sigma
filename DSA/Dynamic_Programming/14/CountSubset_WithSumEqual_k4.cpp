#include <iostream>
#include <vector>
#include <cmath> // for pow
using namespace std;

// the previous 3 parts code was for when the arraay values only include from 1 to infinity, 0 was not included
// this code is for if 0 is included,
/*
Recursive approach to count subsets with sum = target.

Important Note about zeros in the array:
- A zero does NOT change the sum when included in a subset.
- Example: nums = {0, 1, 2}, target = 2
  Subsets ignoring zeros: {2} → 1 subset
  Number of zeros = 1 → multiplying by 2^1 = 2 accounts for subsets:
  {2}, {0,2}

When to do this:
- Only necessary when the array contains one or more zeros.
- This ensures that subsets containing zeros are counted correctly without modifying the recursive logic.

*/

int helper(int n, int sum, vector<int> &nums){
    if(n == 0){ // base case 2
        if(sum == 0 && nums[0] == 0){
            return 2;
        }
        if(sum == 0 && nums[0] != 0){
            return 1;
        }
        if(sum != 0 && nums[0] == sum){
            return 1;
        }
        return 0;
    }

    int not_pick = helper(n-1, sum, nums);

    int pick = 0;
    if(nums[n] <= sum){
        pick = helper(n-1, sum-nums[n], nums);
    }

    return pick + not_pick;
}


int countSubsetsWithSumK(vector<int> &nums, int target){
    int n = nums.size();
    return helper(n-1,target,nums);
}

int main() {
    // Example input
    int sum = 3;
    vector<int> nums = {0, 1, 2, 0, 3};

    int result = countSubsetsWithSumK(nums, sum);
    cout << "Count of subsets with sum " << sum << " = " << result << "\n";

    return 0;
}
