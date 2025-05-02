#include <iostream>
using namespace std;

/* Question: For a given integer array of size N.You have to find all the occurrences(indices) of
a given element(Key) and print them. Use a recursive function to solve this problem.*/
void all_occurences(int arr[], int key, int st, int size){
    if(st == size){
        return;
    }
    if(arr[st] == key){
        cout << st << endl;
    }
    all_occurences(arr,key,st+1,size);
}

int main(){
    int arr[]={3,2,4,5,6,2,7,2,2};
    int key=2;
    int st =0;
    int size = sizeof(arr)/sizeof(arr[0]);
    all_occurences(arr,key,st,size);
    return 0;
}