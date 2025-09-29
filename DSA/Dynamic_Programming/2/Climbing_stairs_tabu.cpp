#include <iostream>
#include <vector>
using namespace std;

/*
Difference from Fibonacci:
       --------------------------
       - Recurrence relation is identical to Fibonacci.
       - The only difference is the base case:
         * Fibonacci(0) = 0, but here ways(0) = 1
           because there is exactly one way to do nothing and remain at step 0.
       - That small shift makes this sequence look like Fibonacci, but offset
*/

int ways(int n, vector<int> &arr){
    arr[0] = 1;
    arr[1] = 1;

    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main(){
    int n = 5;
    vector<int> arr(n+1, -1);

    /*
       Question:
       ----------
       You are climbing a staircase with 'n' steps. 
       You can take either 1 step or 2 steps at a time.
       Find the number of distinct ways to reach the top.

       Logic (Bottom-up DP / Tabulation):
       ----------------------------------
       - Define arr[i] as the number of ways to reach step i.
       - At each step i, you can come from (i-1) or (i-2).
         So, arr[i] = arr[i-1] + arr[i-2].
       - Start with arr[0] = 1 (one way to stay at ground) and arr[1] = 1.
       - Build the array iteratively until n.
.
    */
    cout << ways(n, arr) << endl;
    return 0;
}
