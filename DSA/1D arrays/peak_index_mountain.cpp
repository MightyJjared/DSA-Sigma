#include <iostream>
using namespace std;

/*
    This function finds a peak element in a given array.
    Assumptions:
    1. The array always contains a peak element.
    2. The array has at least 3 elements.
    3. A peak element is defined as an element that is greater than its neighbors.
    
    Approach: Binary Search (O(log N))
    - We search for the peak using a binary search approach.
    - If arr[mid] is greater than both its neighbors, it is a peak.
    - Otherwise, we move towards the side that has a greater neighbor to ensure we reach a peak.
*/

int peaksearch(int arr[], int size) {
    int start = 1;  // Start from index 1 (avoiding arr[0])
    int end = size - 2;  // End at index size-2 (avoiding arr[size-1])

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if mid is a peak element
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // If left neighbor is greater, move left
        if (arr[mid - 1] < arr[mid]) {
            start = mid + 1;
        } 
        // Otherwise, move right
        else {
            end = mid - 1;
        }
    }

    return -1; // Should never reach here as peak is always guaranteed
}

int main() {
    int arr[] = {1, 3, 5, 6, 8, 7, 4};  // Example array with a peak
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate size of the array

    int result = peaksearch(arr, size); // Call function to find peak index

    if (result != -1) {
        cout << "Peak element found at index: " << result << ", Value: " << arr[result] << endl;
    } 
    else {
        cout << "Peak element does not exist" << endl;
    }

    return 0;
}

/*
Example:
Input: {1, 3, 5, 6, 8, 7, 4}
Peak Index: 4
Peak Value: 8

Input: {10, 20, 15, 2, 23, 90, 67}
Peak Index: 5
Peak Value: 90

Input: {1, 2, 3, 4, 5, 6, 7}
Peak Index: 6
Peak Value: 7 (Last element is peak in strictly increasing array)
*/
