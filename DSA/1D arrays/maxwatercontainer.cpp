#include <iostream>
using namespace std;

// brute force
void maxwater(int arr[], int size){
    int maxarea =INT16_MIN;
    for(int i =0; i<size;i++){
        for(int j =i+1; j<size;j++){
            int lenght = j-i;
            int breadth = min(arr[i], arr[j]);
            int area = breadth * lenght;
            maxarea = max(area, maxarea);
        }
    }
    cout << maxarea << endl;
}

// two pointer
void maxwater2(int arr[], int n){
    int leftpointer = 0;
    int rightpointer = n-1;
    int maxwater = INT16_MIN;
    while(leftpointer < rightpointer){
        int length = rightpointer - leftpointer;
        int breadth = min(arr[leftpointer], arr[rightpointer]);
        int area = length * breadth;
        maxwater = max(maxwater, area);
        if(arr[leftpointer] < arr[rightpointer]){
            leftpointer++;
        }
        else if(arr[leftpointer] > arr[rightpointer]){
            rightpointer--;
        }
        else{
            rightpointer--;
        }
    }
    cout << maxwater << endl;
}
int main(){
    int height[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(height)/sizeof(height[0]);
    maxwater2(height,size);
    return 0;
}