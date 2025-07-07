/*
📌 Problem: Minimum Sum of Absolute Differences

You are given two arrays A and B of the same size.

Your task is to:
- Rearrange the elements (i.e., sort them) in both arrays,
- Then compute the sum of absolute differences between their corresponding elements.

The goal is to **minimize the total sum of absolute differences**.

💡 Why sorting works:
Sorting both arrays ensures that similar-sized elements are compared with each other.
This minimizes the total difference because it avoids pairing a small number from A with a large number from B (or vice versa).

📥 Example:
A = {1, 2, 3}
B = {3, 1, 2}

After sorting:
A = {1, 2, 3}
B = {1, 2, 3}

Sum of absolute differences:
|1 - 1| + |2 - 2| + |3 - 3| = 0

✅ Output:
Minimum absolute difference = 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> A = {1, 2, 3};
    vector<int> B = {3, 1, 2};

    // Step 1: Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absolute_difference = 0;

    // Step 2: Compute sum of absolute differences
    for(int i = 0; i < A.size(); i++){
        absolute_difference += abs(A[i] - B[i]); // abs gives positive difference
    }

    // Step 3: Output the result
    cout << "Min absolute differnece = " << absolute_difference << endl;

    return 0;
}
