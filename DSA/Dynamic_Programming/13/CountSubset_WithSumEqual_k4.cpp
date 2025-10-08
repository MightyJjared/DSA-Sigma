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

Why we handle zeros separately:
1. If we include zeros in the recursion normally, each zero could be included/excluded
   at any level, which complicates the base cases.
2. Instead, we first filter out zeros and run recursion/DP on the remaining array.
3. After obtaining the count of subsets ignoring zeros, we multiply the result by 2^number_of_zeros.
   - Each zero doubles the count of subsets because it can either be included or excluded freely.

When to do this:
- Only necessary when the array contains one or more zeros.
- This ensures that subsets containing zeros are counted correctly without modifying the recursive logic.

Steps:
1. Count the number of zeros in the array.
2. Filter out zeros and run the normal recursive helper on the filtered array.
3. Multiply the final answer by 2^number_of_zeros.
*/

int helper(int n, int sum, vector<int> &nums){
    if(sum == 0) return 1;    // base case: sum achieved
    if(n < 0) return 0;       // base case: no elements left

    int not_pick = helper(n-1, sum, nums);
    int pick = 0;
    if(nums[n] <= sum) pick = helper(n-1, sum - nums[n], nums);

    return pick + not_pick;
}

int countSubsetsWithSumK(vector<int> &nums, int target){
    int zeros = 0;
    vector<int> filtered; // array without zeros

    for(int x : nums){
        if(x == 0) zeros++;
        else filtered.push_back(x);
    }

    int ans = helper(filtered.size() - 1, target, filtered);

    // Multiply by 2^zeros to account for subsets including zeros
    return ans * pow(2, zeros);
}

int main(){
    vector<int> nums = {0, 1, 2};
    int target = 2;

    int result = countSubsetsWithSumK(nums, target);
    cout << "Count of subsets with sum " << target << " = " << result << "\n";

    return 0;
}
