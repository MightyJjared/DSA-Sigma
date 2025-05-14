#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Question:
Given an array of integers that may contain duplicates, return all possible subsets (the power set),
ensuring that no duplicate subsets are included in the result.

Example:
Input: [3, 1, 2]
Sorted Input: [1, 2, 3]

All unique subsets:
[]
[1]
[1, 2]
[1, 2, 3]
[1, 3]
[2]
[2, 3]
[3]
*/

void subset(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &arr){
    ans.push_back(ds);
        
    for(int i = index; i< arr.size();i++){
        if(i != index && arr[i] == arr[i-1]){
            continue;
        }
        ds.push_back(arr[i]);
        subset(i+1,ans,ds,arr);
        ds.pop_back();
    }
}
int main(){
    vector<int> arr = {3, 1, 2};
    vector<vector<int>> ans; //to store ds subsets
    vector<int> ds;  // to store a subset
    int index = 0;
    sort(arr.begin(), arr.end());
    subset(index,ans,ds,arr);
    for(int i =0; i< ans.size(); i++){
        for(int j =0; j< ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
