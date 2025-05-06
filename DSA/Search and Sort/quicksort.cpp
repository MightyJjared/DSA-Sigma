#include <iostream>
#include <vector>
using namespace std;

// Partition function using Lomuto partition scheme
int pivot(vector<int> &vec, int st , int end){
    int i = st - 1;
    int pivot = vec[end]; // Choose last element as pivot

    // Traverse and partition
    for(int j = st; j < end; j++){
        if(vec[j] < pivot){
            i++;
            swap(vec[j], vec[i]); // Place smaller element on the left
        }
    }

    // Put pivot in the correct position
    i++;
    swap(vec[i], vec[end]);
    return i; // Return the index of the pivot
}

// Recursive Quick Sort
void quicksort(vector<int> &vec, int st, int end){
    if(st >= end) return;

    int pivotindex = pivot(vec, st, end);

    quicksort(vec, st, pivotindex - 1);   // Sort left
    quicksort(vec, pivotindex + 1, end);  // Sort right
}

int main(){
    vector<int> vec = {6, 1, 8, 3, 9, 23};
    quicksort(vec, 0, vec.size() - 1);

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

