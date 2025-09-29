#include <iostream>
#include <vector>
using namespace std;

/*
 Difference from Fibonacci:
 --------------------------
 - The recurrence relation extends Fibonacci.
 - Instead of just (n-1) + (n-2), here it's (n-1) + (n-2) + (n-3).
 - BUT base case still differs from Fibonacci:
     * Fibonacci(0) = 0, while here ways(0) = 1 
       (because there is exactly one way to do nothing and stay at step 0).
 - This small change shifts the sequence compared to Fibonacci/Tribonacci.
*/

/*
 Question & Logic:
 -----------------
 Problem: You are climbing a staircase with 'n' steps. 
 You can climb either 1, 2, or 3 steps at a time.
 The task is to find how many distinct ways you can reach the top.

 Core Idea (DP with recursion + memoization):
 --------------------------------------------
 - At step 'n', you could have come from:
      (n-1) → taking 1 step
      (n-2) → taking 2 steps
      (n-3) → taking 3 steps
 - So total ways to reach step 'n' = ways(n-1) + ways(n-2) + ways(n-3).
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
        return 2;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] = ways(n-1, arr) + ways(n-2, arr) + ways(n-3, arr);
    return arr[n];
}

int main(){
    int n = 5;
    vector<int> arr(n+1, -1);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    cout << ways(n, arr) << endl;
    return 0;
}
