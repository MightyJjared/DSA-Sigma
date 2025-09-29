#include <iostream>
#include <vector>
using namespace std;

/*
 Difference from Fibonacci:
 --------------------------
 - Fibonacci: f(n) = f(n-1) + f(n-2).
 - Here: ways(n) = ways(n-1) + ways(n-3),
   because you are allowed to climb only 1 step or 3 steps at a time.
 - Base case still differs from Fibonacci:
     * Fibonacci(0) = 0, while here ways(0) = 1 
       (because there is exactly one way to do nothing and stay at step 0).
*/

/*
 Question & Logic:
 -----------------
 Problem: You are climbing a staircase with 'n' steps. 
 You can climb either 1 step or 3 steps at a time.
 The task is to find how many distinct ways you can reach the top.

 Core Idea (DP with recursion + memoization):
 --------------------------------------------
 - At step 'n', you could have come from:
      (n-1) → taking 1 step
      (n-3) → taking 3 steps
 - So total ways to reach step 'n' = ways(n-1) + ways(n-3).
 - Store intermediate results in 'arr' (memoization) to avoid recalculating subproblems.
*/

int ways(int n, vector<int> &arr){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 1; // only path = 1+1
    }

    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] = ways(n-1, arr) + ways(n-3, arr);
    return arr[n];
}

int main(){
    int n = 5;
    vector<int> arr(n+1, -1);

    cout << ways(n, arr) << endl; // Output = 5
    return 0;
}
