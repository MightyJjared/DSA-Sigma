#include <iostream>
using namespace std;

void binarysearch(int arr[], int target, int st, int end){
    if(st > end){ // base case: element not found
        cout << "Not found" << endl;
        return;
    }

    int mid = st + (end - st) / 2; // calculate mid dynamically

    if(arr[mid] == target){
        cout << "Found at index: " << mid << endl;
        return;
    }

    if(target < arr[mid]){
        binarysearch(arr, target, st, mid - 1);
    } else {
        binarysearch(arr, target, mid + 1, end);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int target = 5;
    int st = 0;
    int end = sizeof(arr)/sizeof(arr[0]) - 1;

    binarysearch(arr, target, st, end);

    return 0;
}
