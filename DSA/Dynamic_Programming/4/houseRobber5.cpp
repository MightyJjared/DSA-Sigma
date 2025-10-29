#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation + space optimization (House robber 2)
// This is house robber 2 in leetocde 213 here everything is same except the houses are circular soonly change is
// in the answer the first and last index cant be present simaltaneously because they are also neighbours.
// so what we did is we copied the rob_helper from house robber1 and in the rob function we created 2 vector,
// one include all elemnts except the first and the second one doesnt include the last elemnet,
// so our logic is we will pass both of these to rob helper and the answer will be maximum of thpse 2.
// we also added 2 edge caes in rob helper
class Solution {
public:
    int rob_helper(vector<int>& nums) {
        int n = nums.size();
       
        // ✅ handle small cases
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]); // this is important

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            //take
            int take = prev2 + nums[i];
            // not take
            int not_take = prev1;

            int current = max(take, not_take);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    
    int rob(vector<int> &nums){
        int n = nums.size();
        vector<int> temp1;
        vector<int> temp2;

        if(n==1){
            return nums[0];
        }

        for(int i =0; i< n; i++){
            if(i != 0){
               temp1.push_back(nums[i]);
            }
            if(i != n-1){
               temp2.push_back(nums[i]);
            }
        }

        return max(rob_helper(temp1), rob_helper(temp2));
    }

};

int main() {
    vector<int> nums = {2,7,9,3,1};
    Solution sol;
    cout << sol.rob(nums) << endl; 
    return 0;
}
