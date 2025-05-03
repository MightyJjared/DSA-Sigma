#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves of the array: vec[start to mid] and vec[mid+1 to end]
void merge(vector<int> &vec, int start, int mid, int end){
    int i = start;     // Pointer for left half
    int j = mid + 1;   // Pointer for right half
    vector<int> temp;  // Temporary vector to store the merged result

    // Merge the two halves while comparing elements
    while(i <= mid && j <= end){
        if(vec[i] < vec[j]){
            temp.push_back(vec[i]);  // Smaller element from left half
            i++;
        }
        else{
            temp.push_back(vec[j]);  // Smaller element from right half
            j++;
        }
    }

    // If any elements are left in the left half, add them
    while(i <= mid){
        temp.push_back(vec[i]);
        i++;
    }

    // If any elements are left in the right half, add them
    while(j <= end){
        temp.push_back(vec[j]);
        j++;
    }

    // Copy sorted elements from temp back to original vector
    for(int idx = 0; idx < temp.size(); idx++){
        vec[start + idx] = temp[idx];
    }
}

// Recursive merge sort function
void mergesort(vector<int> &vec, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;  // Find the middle index

        // Recursively sort the left half
        mergesort(vec, start, mid);

        // Recursively sort the right half
        mergesort(vec, mid + 1, end);

        // Merge the two sorted halves
        merge(vec, start, mid, end);
    }
}

int main(){
    vector<int> vec = {6, 1, 8, 3, 9, 23}; // Input array
    int start = 0;
    int end = vec.size() - 1;

    mergesort(vec, start, end);  // Perform merge sort

    // Output the sorted array
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
