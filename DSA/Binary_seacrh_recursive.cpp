#include <iostream>
using namespace std;

int BinarySearchRecursive(int arr[], int target, int start, int end) {
    if (start > end) {
        return -1; // Base case: Target not found
    }

    int mid = start + (end - start) / 2; // Prevents overflow

    if (arr[mid] == target) {
        return mid; // Target found
    } 
    else if (arr[mid] < target) {
        return BinarySearchRecursive(arr, target, mid + 1, end); // Search in the right half
    } 
    else {
        return BinarySearchRecursive(arr, target, start, mid - 1); // Search in the left half
    }
}

int main() {
    int arr[] = {2, 4, 5, 7, 9, 11, 24};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = BinarySearchRecursive(arr, target, 0, size - 1);
    
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } 
    else {
        cout << "Target not found" << endl;
    }

    return 0;
}
