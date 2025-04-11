#include <iostream>
#include <vector>
using namespace std;
// brute force                            
vector<int> ProductArray(vector<int> nums){         
    int n = nums.size();
    vector<int> ans(n,1);
    vector<int> suffix(n,1);
    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }
    for(int i=0; i<n; i++){
        ans[i] = suffix[i] * prefix[i];
    }
    return ans;
}
int main(){
    vector<int> nums = {1,2,3,4};
    vector<int>  result = ProductArray(nums);
    for(int val : result){
        cout << val << endl;
    }

    return 0;
} 