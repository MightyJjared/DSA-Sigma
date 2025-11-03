#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation
/*
🔹 LeetCode 1043: Partition Array for Maximum Sum
-------------------------------------------------
🧩 Problem Summary:
You are given an integer array `arr` and an integer `k`.  
Partition the array into contiguous subarrays of at most length `k`.  
After partitioning, replace every number of each subarray with the
maximum value of that subarray.

Your goal is to return the maximum sum possible after such partitioning.

💡 Example:
Input: arr = [1, 15, 7, 9, 2, 5, 10], k = 3  
Explanation:
We can partition as → [1,15,7], [9,2,5], [10]  
Replace with maxima → [15,15,15,9,9,9,10]  
Sum = 15+15+15+9+9+9+10 = 84 ✅  
Output: 84

🧠 Approach:
- Use Dynamic Programming (Bottom-Up Tabulation)
- `dp[i]` → max sum from index `i` to end.
- For each `i`, we try subarrays of length up to `k`, track the max element,
  and compute the best partition.
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);  // base case: dp[n] = 0

        for (int i = n - 1; i >= 0; i--) {
            int maxi = -1e9;
            int length = 0;
            int maxAns = -1e9;

            for (int j = i; j < i + k && j < n; j++) {
                length++;
                maxi = max(maxi, arr[j]);
                int step = (length * maxi) + dp[j + 1];
                maxAns = max(maxAns, step);
            }

            dp[i] = maxAns;
        }

        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << sol.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}
