#include <iostream>
using namespace std;

// Function to perform Binary Search in a Rotated Sorted Array
int Binarysearch(int arr[], int target, int size) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // Avoids integer overflow

        // If target is found at mid, return the index
        if (arr[mid] == target) {
            return mid;
        }

        // Check if the left half [start...mid] is sorted
        if (arr[start] <= arr[mid]) {
            // If the target lies within the sorted left half
            if (arr[start] <= target && target < arr[mid]) {
                end = mid - 1;  // Search in the left half
            } else {
                start = mid + 1; // Search in the right half
            }
        }
        // Otherwise, the right half [mid...end] is sorted
        else {
            // If the target lies within the sorted right half
            if (arr[mid] < target && target <= arr[end]) {
                start = mid + 1;  // Search in the right half
            } else {
                end = mid - 1;  // Search in the left half
            }
        }
    }

    return -1;  // Target not found
}

int main() {
    // Example: Rotated Sorted Array
    int arr[] = {4, 5, 6, 7, 0, 1, 2};  
    int target = 0; // Number to search
    int size = sizeof(arr) / sizeof(arr[0]); // Finding size of the array

    // Calling Binary Search function
    int result = Binarysearch(arr, target, size);

    // Printing the result
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}
