#include <iostream>
using namespace std;

// Function to find the single element in a sorted array
int SingleElement(int arr[], int n) {
    if (n == 1){
        return arr[0];
    }
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if((mid == 0 || arr[mid] != arr[mid-1] )&& (mid == n-1 || arr[mid] != arr[mid+1])){
            return arr[mid];
        }
        if( mid > 0 && arr[mid] == arr[mid-1]){
            if((mid-start) % 2 == 0){
                end = mid-2;
            }
            else{
                start = mid +1;
            }
        }
        else if(arr[mid] == arr[mid+1] && mid < n-1){
            if((end-mid) % 2 == 0){
                start = mid+2;
            }
            else{
                end = mid-1;
            }
        }
        }
    return -1;
} 

int main() {
    // Example 1: Single element in the middle
    int arr1[] = {1, 1, 3, 3, 5, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Single element found: " << SingleElement(arr1, n1) << endl;  // Output: 7

    // Example 2: Single element at the start
    int arr2[] = {2, 4, 4, 5, 5, 8, 8, 9, 9}; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Single element found: " << SingleElement(arr2, n2) << endl;  // Output: 2

    // Example 3: Single element at the end
    int arr3[] = {3, 3, 6, 6, 9, 9, 11}; 
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Single element found: " << SingleElement(arr3, n3) << endl;  // Output: 11

    // Example 4: Single element in a larger array
    int arr4[] = {1, 1, 2, 2, 3, 3, 4, 4, 6, 6, 7, 7, 9, 10, 10, 11, 11}; 
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Single element found: " << SingleElement(arr4, n4) << endl;  // Output: 9

    // Example 5: Single element appearing first
    int arr5[] = {5, 6, 6, 7, 7, 8, 8, 9, 9}; 
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "Single element found: " << SingleElement(arr5, n5) << endl;  // Output: 5

    // Example 6: Only one element in the array
    int arr6[] = {99}; 
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "Single element found: " << SingleElement(arr6, n6) << endl;  // Output: 99

    // Example 7: Single element somewhere in a rotated sorted array
    int arr7[] = {4, 4, 7, 7, 9, 10, 10, 11, 11, 12, 12}; 
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    cout << "Single element found: " << SingleElement(arr7, n7) << endl;  // Output: 9

    return 0;
}
