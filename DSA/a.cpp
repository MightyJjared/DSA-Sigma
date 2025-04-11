#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i =0; i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionsort(int arr[], int n){
    for(int i =0; i< n-1;i++){
        int minidx = i;
        for(int j =i+1;j<n;j++){
            if(arr[j] < arr[minidx]){
                minidx = j;
            }
        }
        swap(arr[i], arr[minidx]);
    }
}

void insertionsort(int arr[], int n){
    for(int i =1;i<n;i++){
        int current = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev] > arr[current]){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = current;
    }
}

void countsort(int arr[], int n){
    int freq[10000] = {0};
    int minval = INT16_MAX, maxval = INT16_MIN;
    for(int i =0;i<n;i++){
        minval = min(minval, arr[i]);
        maxval = max(maxval, arr[i]);
    }

    for(int i=0; i<n; i++){
        freq[arr[i]] += 1;
    }
    for(int i = minval,j=0;i<=maxval;i++){
        while(freq[i]>0){
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}
int main(){
    int arr[] = {5,3,1,4,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    countsort(arr,n);
    for(int i =0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
 
}