#include <iostream>
#include <vector>
using namespace std;

// swap method, very imp , explanation - taku u forward print permutation approach 2 video
void permutations(int index,vector<int> &arr, vector<vector<int>> &ans){
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i =index;i<arr.size();i++){
        swap(arr[i], arr[index]);
        permutations(index +1,arr,ans);
        swap(arr[i],arr[index]);
    }
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    permutations(0,arr,ans);
    for(int i =0; i< ans.size(); i++){
        for(int j =0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}