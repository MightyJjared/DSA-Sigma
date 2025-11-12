#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// recursive
// this is strivers dp 48, this is classical,to understand aproach see the complete video
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

int helper(int i, int j, vector<int> &arr){
    if(i == j){
        return 0;
    }

    int minimum = 1e9;
    for(int k = i; k <= j-1; k++){
        int steps = arr[i-1] * arr[k] * arr[j]
                    + helper(i, k, arr)
                    + helper(k+1, j, arr);
        
        minimum = min(steps, minimum);
    } 
    return minimum;
}

int matrixMultiplication(vector<int> &arr, int N) {
    return helper(1, N-1, arr);
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 30};
    int N = arr.size();

    cout << "Minimum multiplications: " << matrixMultiplication(arr, N) << endl;
    return 0;
}
