#include <iostream>
#include <vector>
using namespace std;
// brute force approach
vector<int> SumPair(vector<int> nums, int target){
    vector<int> ans;
    int n = 4;
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
return ans;
}

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
    vector<int> nums = {2,7,11,14};
    int target = 18;
    vector<int> ans =SumPair(nums,target);
    cout << ans[0] << "," << ans[1] << endl;
    return 0;

}