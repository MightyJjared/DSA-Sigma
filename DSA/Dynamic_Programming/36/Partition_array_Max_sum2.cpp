#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// memoization
/*
🔹 LeetCode 1043: Partition Array for Maximum Sum
-------------------------------------------------
🧩 Problem Summary:
Given an array `arr` and an integer `k`, partition the array into
contiguous subarrays of at most length `k`. Replace each subarray’s 
elements with its maximum value and find the maximum possible sum.

🧠 Example:
Input: arr = [1,15,7,9,2,5,10], k = 3  
Output: 84  
Explanation: Partition the array as [1,15,7], [9,2,5], [10]  
→ After replacement = [15,15,15,9,9,9,10]  
→ Sum = 15 + 15 + 15 + 9 + 9 + 9 + 10 = 84 ✅
*/

class Solution {
public:
    int helper(int i, int k, vector<int>& arr, int n, vector<int> &dp){
        if(i == n){ // base case
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int maxi = -1e9;
        int length = 0;
        int maxAns = -1e9;

        for(int j = i; j < i + k && j < n; j++){
            length++;
            maxi = max(maxi, arr[j]);
            int step = (length * maxi) + helper(j+1, k, arr, n, dp);
            maxAns = max(maxAns, step);
        }

        return dp[i] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(0, k, arr, n, dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << sol.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}
