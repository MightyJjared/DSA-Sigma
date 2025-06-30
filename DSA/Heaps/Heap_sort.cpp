#include <iostream>
#include <vector>
using namespace std;

// this is in ascending order using max heap 
// if we want we can do descending using min heap by changing > in line 12 and 15 to <.
void heapify(int parent, vector<int> &vec, int size){
    int leftchild = (2*parent) + 1;
    int rightchild = (2*parent) + 2;
    int max = parent;

    if(leftchild < size && vec[leftchild] < vec[max]){
        max = leftchild;
    }
    if(rightchild < size && vec[rightchild] < vec[max]){
        max = rightchild;
    }

    if(max != parent){
        swap(vec[max], vec[parent]);
        heapify(max, vec, size);
    }
}

void heapsort(vector<int> &vec, int size){
    // 1 Step
    for(int i = (size/2) - 1; i >= 0; i--){
        heapify(i,vec,size);
    }

    // 2 Step
    for(int i = size-1; i >= 0; i--){
        swap(vec[0], vec[i]);
        heapify(0, vec, i);
    }
}
int main(){
    vector<int> vec = {5,2,8,1,9};
    int size = vec.size();

    heapsort(vec, size);

    for(int i = 0; i < size; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}