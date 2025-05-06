#include <iostream>
using namespace std;

int search(int arr[], int target,int start,int end){
    if(start > end){
        return -1;
    }
        int mid = start + (end-start)/2;

        if(arr[mid] == target){
            return mid;
        }
        if(arr[start] <= arr[mid]){
            if(arr[start]<= target && target <= arr[mid]){
                return search(arr,target,start,mid-1);
            }
            else{
                return search(arr,target,mid+1,end);

            }
        }
        else{
            if(arr[mid] <= target && target <= arr[end]){
               return search(arr,target,mid+1,end);

            }
            else{
                return search(arr,target,start,mid-1);
            }
        }
}

int main(){
    int arr[] = {4,5,6,7,0,1,2,3};
    int target = 6;
    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0]) - 1;
    int result = search(arr, target,start,end);
    if(result == -1){
        cout << "Target not found" << endl;
    }
    else{
        cout << result << endl;
    }
    return 0;
}