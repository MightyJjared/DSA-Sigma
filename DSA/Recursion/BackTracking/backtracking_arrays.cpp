#include <iostream>
using namespace std;
/*
void printarr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changearr(int arr[], int size, int i){
    if(i == size){
        printarr(arr,size);
        return;
    }
    arr[i] = i+1;
    changearr(arr,size,i+1);
}

int main(){
    int arr[5] = {0};
    int size = 5;
    changearr(arr,size,0);
    return 0;
}*/

void printarr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changearr(int arr[], int size, int i){
    if(i == size){
        printarr(arr,size);
        return;
    }
    arr[i] = i+1;
    changearr(arr,size,i+1);
    arr[i] = arr[i] -2;

}

int main(){
    int arr[5] = {0};
    int size = 5;
    changearr(arr,size,0);
    printarr(arr,size);
    return 0;
}