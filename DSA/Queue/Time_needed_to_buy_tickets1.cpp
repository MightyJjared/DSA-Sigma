#include <iostream>
#include <queue>
using namespace std;

int timeRequiredToBuy1(int arr[], int n, int k){
    int count = 0;
    while(arr[k] > 0){
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                arr[i]--;
                count++;
            }
            if(arr[k] == 0){
                break;
            }
        }
    }
    return count;
}


int main(){
    int arr[] = {5,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 0;

    cout << timeRequiredToBuy1(arr, n, k) << endl;
    return 0;
}
