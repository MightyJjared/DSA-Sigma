#include <iostream>
#include <algorithm>
using namespace std;

bool isvalid(int arr[], int n, int m, int mid){
    int cowcount = 1;
    int last_position = arr[0];
    for(int i =1;i<n;i++){
        if(arr[i]-last_position >= mid){
            cowcount ++;
            if(cowcount == m){
                return true;
            }
            last_position = arr[i];
        }
    }
    return false;
}

int binarysearch(int arr[], int n, int m){
    sort(arr,arr+n);
    int maxi = INT8_MIN;
    for(int i=0; i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    int start = 0;
    int end = maxi;
    int ans = 0;
    while(start<=end){
        int mid = start + (end-start)/2;
        if (isvalid(arr,n,m,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }   
    }
    return ans;
}

int main(){
    int arr[] = {1,2,8,4,9};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int m = 3;
    int result = binarysearch(arr,n,m);
    cout << result << endl;

    return 0;

}