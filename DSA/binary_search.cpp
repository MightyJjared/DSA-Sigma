#include <iostream>
using namespace std;

int Binarysearch(int arr[], int target, int size){
    int start = 0;
    int end = size-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] < target){
            start = mid + 1;
        }
        else if (arr[mid] > target){
            end = mid-1;
        }
        else if(arr[mid] == target){
            return mid;
        }
    }
return -1;

}

int main(){
    int arr[] = {2,4,5,7,9,11,24};
    int target = 9;
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = Binarysearch(arr, target, size);
    if( result != -1){
        cout << "Target found at index : " << result << endl;
    }
    else{
        cout << "Target not found" << endl;
    }

    return 0;
}