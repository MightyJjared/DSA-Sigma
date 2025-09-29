#include <iostream>
#include <vector>
using namespace std;

/*
 Difference from Fibonacci:
       --------------------------
       - The recurrence relation is the same as Fibonacci.
       - BUT base case differs:
           * Fibonacci(0) = 0, while here ways(0) = 1 
             (because there is exactly one way to do nothing and stay at step 0).
       - This small change shifts the sequence compared to Fibonacci.
       */

int ways(int n, vector<int> &arr){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] = ways(n-1, arr) + ways(n-2, arr);
    return arr[n];
}

int main(){
    int n = 5;
    vector<int> arr(n+1, -1);
    arr[0] = 1;
    arr[1] = 1;

    /* 
       Question & Logic:
       -----------------
       Problem: You are climbing a staircase with 'n' steps. 
       You can climb either 1 step or 2 steps at a time.
       The task is to find how many distinct ways you can reach the top.

       Core Idea (DP with recursion + memoization):
       --------------------------------------------
       - At step 'n', you could have come from step (n-1) or step (n-2).
       - So total ways to reach step 'n' = ways(n-1) + ways(n-2).
       - Store intermediate results in 'arr' (memoization) to avoid recalculating subproblems.
    */
    cout << ways(n, arr) << endl;
    return 0;
}
