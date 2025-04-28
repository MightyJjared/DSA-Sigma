#include <iostream>
using namespace std;

void reverse_array(int arr[], int size){
    int start = 0;
    int last = size-1;
    while(start < last){
        swap(arr[start], arr[last]);
        start++;
        last--;
    }
}

int main(){
    int arr[] = {4,6,2,7,5,9,12};
    int size = 7;
    reverse_array(arr, 7);

    cout << "Reversed array is " << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}