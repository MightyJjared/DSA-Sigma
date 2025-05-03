#include <iostream>
#include <vector>
using namespace std;

int pivot(vector<int> &vec, int st , int end){
    int i =st-1;
    int pivot = vec[end];
    for(int j = st; j< end; j++){
        if(vec[j] < pivot){
            i++;
            swap(vec[j], vec[i]);
        }
    }
    i++;
    swap(vec[i], vec[end]);
    return i;
}
void quicksort(vector<int> &vec, int st, int end){
    if(st >= end){
        return;
    }
    int pivotindex = pivot(vec, st, end);

    quicksort(vec, st, pivotindex-1);
    quicksort(vec, pivotindex+1, end);
   
}

int main(){
    vector<int> vec = {6, 1, 8, 3, 9, 23}; // Input array
    int start = 0;
    int end = vec.size() - 1;

    quicksort(vec, start, end);  // Perform quick sort

    // Output the sorted array
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
