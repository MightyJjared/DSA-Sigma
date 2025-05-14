#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question - Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// The solution set must not contain duplicate combinations.
// example1 - Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
// example 2 - Input: candidates = [2,5,2,1,2], target = 5
// Output: [[1,2,2],[5]]
// Video explanation - TUF recursive series, backtracking (Combination Sum II)

void combinationsum2(int index, int target, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr){
    if(target == 0){ // base case - valid combination
        ans.push_back(ds);
        return;
    }

    for(int i = index; i < arr.size(); i++){
        if(i > index && arr[i] == arr[i-1]) continue; // skip duplicates

        if(arr[i] > target) break; // no need to proceed further if element exceeds target

        ds.push_back(arr[i]);
        combinationsum2(i+1, target - arr[i], ds, ans, arr); // i+1 because we can’t reuse the same element
        ds.pop_back();
    }
}

int main(){
    vector<int> arr = {10,1,2,7,6,1,5}; // input array (can contain duplicates)
    int target = 8; // target sum
    vector<vector<int>> ans; // stores all the valid combinations
    vector<int> ds; // temporary vector to store current combination
    int index = 0;

    sort(arr.begin(), arr.end()); // sort to handle duplicates
    combinationsum2(index, target, ds, ans, arr);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
