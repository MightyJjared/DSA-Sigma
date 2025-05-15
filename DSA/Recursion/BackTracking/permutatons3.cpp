#include <iostream>
#include <vector>
using namespace std;

// swap method, very imp , explanation - taku u forward print permutation approach 2 video
void permutations(int index,vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(index == arr.size()){
        ans.push_back(ds);
        return;
    }
    for(int i =0; i<arr.size(); i++){
        int current = arr[i];
        ds.push_back(arr[i]);
        vector<int> temp = arr;
        temp.erase(temp.begin() + i);
        permutations(index,temp,ans,ds);
        ds.pop_back();
    }
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> ds;
    permutations(0,arr,ans,ds);
    for(int i =0; i< ans.size(); i++){
        for(int j =0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}