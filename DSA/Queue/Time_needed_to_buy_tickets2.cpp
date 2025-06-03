#include <iostream>
#include <queue>
using namespace std;

int timeRequiredToBuy(int arr[], int n, int k){
    queue<int> q;
    for(int i =0; i< n;i++){
        q.push(i);
    }
    int count = 0;
    while(arr[k] > 0){
        if(arr[q.front()] > 0){
            count ++;
            arr[q.front()]--;
            if(arr[q.front()] > 0){
                q.push(q.front());
                q.pop();
            }
            else{
                q.pop();
            }
        }
    }
    return count;
}

int main(){
    int arr[] = {5,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 0;

    cout << timeRequiredToBuy(arr, n, k) << endl;
    return 0;
}