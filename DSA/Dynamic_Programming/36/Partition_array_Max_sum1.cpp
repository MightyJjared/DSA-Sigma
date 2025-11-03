#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// recursive
/*
🔹 LeetCode 1043: Partition Array for Maximum Sum
-------------------------------------------------
🧩 Problem Summary:
Given an integer array 'arr' and an integer 'k', partition the array into
contiguous subarrays, each having at most length 'k'. 
After partitioning, replace every element in each subarray with the 
maximum value of that subarray. 

Return the maximum sum of the entire array after partitioning.

🧠 Example:
Input: arr = [1,15,7,9,2,5,10], k = 3
Possible partitioning: [1,15,7], [9,2,5], [10]
After replacement → [15,15,15,9,10,10,10]
Sum = 15+15+15+9+9+9+10 = 84 ✅
*/

class Solution {
public:
    int helper(int i, int k, vector<int>& arr, int n){
        if(i == n){ // base case
            return 0;
        }

        int maxi = -1e9;
        int length = 0;
        int maxAns = -1e9;

        for(int j = i; j < i + k && j < n; j++){
            length++;
            maxi = max(maxi, arr[j]);
            int step = (length * maxi) + helper(j+1, k, arr, n);
            maxAns = max(maxAns, step);
        }

        return maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return helper(0, k, arr, n);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << sol.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}
