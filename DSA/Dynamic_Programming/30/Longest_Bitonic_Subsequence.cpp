#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for logic see striver dp 46 it is easy
/*
🔹 Problem: Longest Bitonic Subsequence (LBS)
🔹 Explanation:
A bitonic subsequence is a sequence that first strictly increases 
and then strictly decreases.

However, it can also be entirely increasing or entirely decreasing.

Example:
Input: [1, 11, 2, 10, 4, 5, 2, 1]
One possible bitonic subsequence: [1, 2, 10, 4, 2, 1]
Here, it increases till 10 → (1 → 2 → 10) and then decreases → (10 → 4 → 2 → 1)
Output: 6
*/

class Solution {
public:
    int longestBitonicSubsequence(vector<int>& nums) {
        int n = nums.size();

        // computing dp1 from index 0 to n
        vector<int> dp1(n, 1);
        for(int i =0; i <n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && dp1[i] < 1 + dp1[prev]){
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }

        // computing dp2 from index n to 0
        vector<int> dp2(n, 1);
        for(int i =n-1; i >= 0; i--){
            for(int prev = n-1; prev > i; prev--){
                if(nums[prev] < nums[i] && dp2[i] < 1 + dp2[prev]){
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }
        
        int maximum = 1;
        for(int i =0; i<n; i++){
            maximum = max(maximum, dp1[i] + dp2[i] -1);
        }
        return maximum;
    }
};

int main() {
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    Solution sol;
    cout << "Length of Longest Bitonic Subsequence: " 
         << sol.longestBitonicSubsequence(nums) << endl;
    return 0;
}
