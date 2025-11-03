#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursive ( if we see it going from top to bottom we will see that left side and right are dependent on each other
// and we cant partion them but if we see from bottom up we can compute them differenntly as they will not be 
// independent (see striver dp 51 for clarity)
/*
🔹 LeetCode Reference: 312. Burst Balloons
---------------------------------------------------------
You are given n balloons, each with a number on it.
You may burst them in any order. When you burst balloon i,
you gain nums[i-1] * nums[i] * nums[i+1] coins.
Return the maximum coins you can collect.
*/

class Solution {
public:
    int helper(int i, int j, vector<int> &nums) {
        if(i > j) {
            return 0;
        }

        int maximum = -1e9;
        for(int k = i; k <= j; k++) {
            int steps = nums[i-1] * nums[k] * nums[j+1]
                        + helper(i, k-1, nums)
                        + helper(k+1, j, nums);
            
            maximum = max(maximum, steps);
        }
        return maximum;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return helper(1, n, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 5, 8};

    cout << "Maximum coins: " << sol.maxCoins(nums) << endl;

    return 0;
}
