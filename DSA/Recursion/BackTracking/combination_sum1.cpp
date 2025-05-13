#include <iostream>
#include <vector>
using namespace std;

// Question - Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order
// example1 - Input: candidates = [2,3,6,7], target = 7. 
// Output: [[2,2,3],[7]
// example 2 - Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Video explanation - taku u forward youtube recursive series lecture 8 or video 10.

void combinationsum(int index, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr){
    if(index == arr.size()){ // basecase
        if(target == 0){      // if we have the correct combination add it to ans vector
            ans.push_back(ds);
        }
        return;
    }

    if(arr[index] <= target){
        ds.push_back(arr[index]);
        combinationsum(index,target-arr[index],ds,ans,arr);
        ds.pop_back();
    }

    combinationsum(index+1,target,ds,ans,arr);
}
int main(){
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans; // vector which contains all answer vectors
    vector<int> ds; // vector which will contain an answer array
    int index =0; 
    combinationsum(index,target,ds,ans,arr);
    for(int i =0;i< ans.size(); i++){
        for(int j =0; j<ans[i].size(); j++){
        cout << ans[i][j] << " ";
    }
    cout << endl;
}
    cout << endl;
    return 0;
}