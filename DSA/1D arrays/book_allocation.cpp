#include <iostream>
using namespace std;

bool isvalid(int arr[], int n, int m, int mid){
    int pages =0, students = 1;
    for(int i = 0; i<n;i++){
        if(arr[i] > mid){
            return false;
        }
        if(pages + arr[i] <= mid){
            pages += arr[i];
        }
        else{
            students ++;
            pages = arr[i];
        }
    }
    if(students >  m){
        return false;
    }
    else{
        return true;
    }
}

int binary_search(int arr[], int n, int m){
    int start = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i]; 
    }
    int end = sum;
    int ans = 0;

    while(start <= end){
        int mid = start + (end-start)/2;
        if (isvalid(arr, n,m,mid)){
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
    int arr[] = {2,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 2;
    int result = binary_search(arr,n,m);
    cout << result << endl;
    return 0;

}