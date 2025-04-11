#include <iostream>
using namespace std;

// Function to find the single element in a sorted array
int SingleElement(int arr[], int n) {
    // Edge cases: if the single element is at the start or end
    if (n == 1 || arr[0] != arr[1]) return arr[0];  // Case: First element is unique
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1]; // Case: Last element is unique

    // Iterate through the array to find the unique element
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]) {
            return arr[i];  // Found the single element
        }
    }
    return -1; // Should never reach here if input is valid
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

    return 0;
}
