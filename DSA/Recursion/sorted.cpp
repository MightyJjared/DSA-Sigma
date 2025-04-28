#include <iostream>
using namespace std;

// We are checking if the array is sorted or not

bool issorted(int arr[], int n, int idx){
    if(idx == n-1){ // base case
        return true;
    }
    if(arr[idx] > arr[idx+1]){
        return false;
    }
    return issorted(arr,n,idx+1);
}

int main(){
    int arr1[] = {6,2,4,9,1,8};
    int arr2[] = {1,2,3,4,5,6};
    cout << issorted(arr1,6,0) << endl;
    return 0;
}