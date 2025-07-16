#include <iostream>
using namespace std;

// leet code 410
bool isvalid(int arr[], int n, int m, int maxallowedtime){
    int painters = 1;
    int time =0;
    for(int i =0;i<n;i++){
        if(arr[i] > mid){
            return false;
        }
        if(arr[i] + time <= mid){
            time += arr[i];
        }
        else{
            painters ++;
            time = arr[i];
        }
    }
    if( painters > m){
        return false;
    }
    else{
        return true;
    }

}

int binarysearch(int arr[], int n, int m){
    int sum = 0;
    for(int i =0;i<n;i++){
        sum += arr[i];
    }
    int start = 0;
    int end = sum;
    int ans = 0;
    while(start<end){
        int mid = start + (end-start)/2;
        if (isvalid(arr,n,m,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }   
    }
    return ans;
}

int main(){
    int arr[] = {40,30,10,20};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int m = 2;
    int result = binarysearch(arr,n,m);
    cout << result << endl;

    return 0;

}