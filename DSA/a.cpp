#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int i = low;
    int j = mid+1;
    while(i<=mid && j <= high){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size();idx++){
        arr[low+idx]= temp[idx];
    }
}

void mergesort(int arr[], int low, int high){
    if(low >= high){
        return;
    }
    int mid = low + (high-low)/2;

    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);

}
int main(){
    int arr[] = {5,2,7,1,8,2,9};
    int low = 0;
    int high = 6;
    mergesort(arr,low,high);
    for(int i =0; i<7;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0; 
}