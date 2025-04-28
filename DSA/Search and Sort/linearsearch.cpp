#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int target){
    for(int i=0;i<size;i++){
        if (target == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[5] = {4,6,2,7,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    cout << "Index of " << target << " is " << linearsearch(arr,size,target) << endl;
    return 0;
}