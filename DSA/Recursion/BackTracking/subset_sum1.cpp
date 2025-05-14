#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetsum(int index, int sum, vector<int> &ans, int arr[],int n){
    if(index == n){
        ans.push_back(sum);
        return;
    }
    subsetsum(index+1,sum+arr[index],ans,arr,n);// adding current index value to sum ie picking

    subsetsum(index+1,sum,ans,arr,n);// not adding current index value to sum ie not picking

}

int main(){
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    int index =0;
    int sum =0;
    subsetsum(index,sum,ans,arr,n);
    sort(ans.begin(), ans.end());
    for( int i : ans){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}