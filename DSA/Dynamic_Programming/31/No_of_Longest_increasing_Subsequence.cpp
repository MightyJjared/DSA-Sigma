#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for explanation see striver dp 47
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int maximum = 1;
        for(int i =1; i <n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev] && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    count[i] = count[prev];
                }
                else if(nums[i] > nums[prev] && dp[prev] + 1 == dp[i]){
                    count[i] += count[prev];
                }
            }
            maximum = max(maximum, dp[i]);
        }

        int ans = 0;
        for(int i =0; i < n; i++){
            if(dp[i] == maximum){
                // There can be multiple indices 'i' where LIS length = maximum.
                // Each represents a different ending point of a longest subsequence,
                // so we ADD their counts instead of overwriting.
                ans += count[i];
                // we are doing ans += count[i] instead of ans = count[i]
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 4, 7};
    Solution obj;
    cout << "Number of LIS: " << obj.findNumberOfLIS(nums) << endl;
    return 0;
}
