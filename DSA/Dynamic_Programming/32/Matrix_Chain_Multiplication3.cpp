#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// tabulation
/*
here since it is tabulation the approach is bottom up and in the nested loop since in memoization we were going
from i =1 to n-1 here the outer loop will rin reverse ie from n-1 to 1 but the second loop in our nested loop
was running from n-1 to 1 but here it should be reverse right and we will reverse it ie it will run form 1 to n-1
but think logically j will always be grater than i or if they are equal answer will be 0 so we will run the 2 loop
from i+1 to n-1 instead of 1 to n-1 we can also run from i to n-1 but it wont make a differnce
// everything lse is copy paste from memoization
*/
/*
🔹 Problem: Matrix Chain Multiplication (MCM)
---------------------------------------------
You are given an array `arr[]` of size N, where arr[i] represents
the dimension of the i-th matrix such that:
Matrix A1 = arr[0] x arr[1]
Matrix A2 = arr[1] x arr[2]
...
Matrix A(N-1) = arr[N-2] x arr[N-1]

Your task:
Find the minimum number of scalar multiplications needed to
multiply all the matrices together.

🔹 Example:
Input: arr = [10, 20, 30, 40, 30]
Output: 30000

Explanation:
There are 4 matrices: A1(10x20), A2(20x30), A3(30x40), A4(40x30)
One optimal way: ((A1*A2)*A3)*A4 → total multiplications = 30000
*/

int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int> (N, 0));

    for(int i =0; i < N; i++){ // base case
        dp[i][i] = 0;
    }

    for(int i = N-1; i >= 1; i--){
        for(int j = i+1; j < N; j++){
            int minimum = 1e9;
            for(int k = i; k <= j-1; k++){
                int steps = arr[i-1] * arr[k] * arr[j]
                            + dp[i][k]
                            + dp[k+1][j];
                
                minimum = min(steps, minimum);
            }
            dp[i][j] = minimum;
        }
    }
    return dp[1][N-1];
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 30};
    int N = arr.size();

    cout << "Minimum multiplications: " << matrixMultiplication(arr, N) << endl;
    return 0;
}
