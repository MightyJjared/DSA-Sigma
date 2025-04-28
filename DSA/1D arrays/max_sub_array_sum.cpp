#include <iostream>
using namespace std;

// brute force approach
void bruteforce(int arr[], int size){
    int maxsum = INT16_MIN;
    for(int i =0; i<size;i++){
        for(int j =i; j<size;j++){
            int currentsum =0;
            for(int k=i;k<=j;k++){
                currentsum += arr[k];
            }
            maxsum = max(currentsum, maxsum);
            cout << endl;
        }
    }
    cout << "Max sum is : " << maxsum << endl;
}
 void optimized(int arr[], int size){
    int maxsum = INT16_MIN;
    for(int start =0; start < size; start++){
        int currentsum = 0;
        for(int end = start; end < size; end++){
            currentsum += arr[end];
            maxsum = max(currentsum, maxsum);
        }
        cout << endl;
    }
    cout << "Max sum is : " << maxsum << endl;
}

void kadanes(int arr[], int size){
    int maxsum = INT16_MIN;
    int currentsum =0;
    for(int i =0; i< size ; i++){
        currentsum = currentsum + arr[i];
        maxsum = max(currentsum, maxsum);

        if(currentsum < 0){
            currentsum =0;
        }
    }
    cout << "Max sum is : " << maxsum << endl;
}
int main(){
    int arr[] = {-2,1,3,4,-1};
    int size = sizeof(arr)/sizeof(arr[0]);
    kadanes(arr, size);
    return 0;
}