#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int> &arr){
    arr[0] = 0;
    arr[1] = 1;

    for(int i =2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    } 
    return arr[n];
}

int main(){
    int n = 5;
    vector<int> arr(n+1, -1);
    cout << fibonacci(n, arr) << endl;
    return 0;
}