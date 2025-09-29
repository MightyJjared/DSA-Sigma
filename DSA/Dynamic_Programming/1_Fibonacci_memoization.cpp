#include <iostream>
#include <vector>
using namespace std;

/* 
       Core DP (memoization) logic:
       Instead of recalculating fibonacci(n-1) and fibonacci(n-2) every time
       through plain recursion (which causes exponential repeated work),
       we store each result in the array 'arr' the first time it is computed.
       Then, whenever the same subproblem is needed again, we simply reuse
       the stored value in O(1) time. This reduces the time complexity
       from exponential O(2^n) in naive recursion to linear O(n).
    */

int fibonacci(int n, vector<int> &arr){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] = fibonacci(n-1, arr) + fibonacci(n-2, arr);
    return arr[n];
}

int main(){
    int n = 5;
    vector<int> arr(n+1, -1);
    arr[0] = 0;
    arr[1] = 1;
    cout << fibonacci(n, arr) << endl;
    return 0;
}