#include <iostream>
using namespace std;
// idea is the largest element will come to an end after comparing with adjacent elements  in each iteration
void bubblesort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool isSwap = false;
        for(int j= 0; j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(isSwap == false){
            return;
        }
    }
}

// here we will assume two parts sorted and unsorted
// at start complete array will be unsorted
// here we will try to bring the smallest element in the start in each iteration
void selectionsort(int arr[], int n){
    for(int i =0;i<n-1;i++){
        int smallest = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }
}

// here we will divid ethe array into sorted and unsorted and assume the first eleemnt as sorted and the rest as unsorted
// now we will compare the first element from unsorted 
// with the elemnts of sorted and place it acccordinly in the sorted part
// we can imagine it as playing cards and placing them correctly at start
void insertionsort(int arr[], int n){
    for(int i =1;i<n;i++){
        int current = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > current){
            arr[prev+1] = arr[prev];
            prev --;
        }
        arr[prev+1] = current;
    }
}
// {5,2,3,7,8}, {2,5,3,7,8}, {2,3,5,7,8} , {2,3,5,7,8}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {5,2,3,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr, n);
    printarray(arr, n);
    return 1;
}