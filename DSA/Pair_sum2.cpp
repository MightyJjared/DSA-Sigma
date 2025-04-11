#include <iostream>
#include <vector>
using namespace std;
// better than brute force approach with time complexity of O(n)
vector<int> SumPair(vector<int> nums, int target){
    vector<int> ans;
    int n = nums.size();
    int i =0; 
    int j = n-1;
    while(i<j){
        if(nums[i]+ nums[j] > target){
            j--;
        }
        else if(nums[i]+ nums[j] < target){
            i++;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
return ans;
}

int main(){
    vector<int> nums = {2,7,11,13,15,14};
    int target = 24;
    vector<int> ans =SumPair(nums,target);
    cout << ans[0] << "," << ans[1] << endl;
    return 0;
}