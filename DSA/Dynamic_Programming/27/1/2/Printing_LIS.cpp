#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// printing
// this is the non intiutive approach striver gave because through this we can easily print the sequence and also
// it helps in solving different problems (striver dp 42)
/*
🔹 LeetCode Reference: 300. Longest Increasing Subsequence
🔹 Problem Explanation:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101].
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        vector<int> hash(n);
        for(int i =0; i < n; i++){
            hash[i] = i;
        }

        int maximum = 1;
        int index = 0;
        for(int i =0; i <n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            //maximum = max(maximum, dp[i]);
            if(dp[i] > maximum){
                maximum = dp[i];
                index = i;
            }
        }

        // We use a parent (hash) array to keep track of the previous index that contributed 
        // to each element’s LIS value. After filling dp[], we backtrack using this hash array 
        // to reconstruct and print the actual Longest Increasing Subsequence.

        vector<int> ans;
        ans.push_back(nums[index]);

        while(hash[index] != index){
            index = hash[index];
            ans.push_back(nums[index]);
        }
        reverse(ans.begin(), ans.end());

        cout << "Sequence = ";
        for(auto itr : ans){
            cout << itr << " ";
        }
        cout << endl;

        return maximum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 4, 11, 1, 16, 8}; // Example input
    cout << "Length = " << sol.lengthOfLIS(nums) << endl; // Expected output: 3
    return 0;
}
