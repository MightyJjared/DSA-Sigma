#include <iostream>
using namespace std;


void dutchnationalflag(int arr[], int size){
    int low =0, mid =0, high = size-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid]== 2){
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}
void sort(int arr[], int size){
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i =0; i< size; i++){
        if(arr[i] == 0){
            count0 += 1;
        }
        if(arr[i] == 1){
            count1 += 1;
        }
        if(arr[i] == 2){
            count2 += 1;
        }
    }
    int idx =0;
    for(int i =0 ; i< count0; i++){
        arr[idx] = 0;
        idx++;
    }
    for(int i =0 ; i< count1; i++){
        arr[idx] = 1;
        idx++;
    }
    for(int i =0 ; i< count2; i++){
        arr[idx] = 2;
        idx++;
    }

}

int main(){
    int arr[] = { 2,1,1,0,2,2,1,0,0,1,2,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    dutchnationalflag(arr,size);
     cout << "Sorted array is : " << endl;
     for(int i =0 ; i< size ; i++){
        cout << arr[i] ;
     }
     cout << endl;
    return 0;
}