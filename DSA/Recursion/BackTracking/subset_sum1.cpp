#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

/*
    Question: Given an array of integers, find the **sum of all possible subsets**.
    You are required to return all subset sums in **sorted order**.

    Example:
    Input: arr = {3, 1, 2}
    Subsets and their sums:
    - []         -> 0
    - [3]        -> 3
    - [1]        -> 1
    - [2]        -> 2
    - [3,1]      -> 4
    - [3,2]      -> 5
    - [1,2]      -> 3
    - [3,1,2]    -> 6

    Output: 0 1 2 3 3 4 5 6
*/

void subsetsum(int index, int sum, vector<int> &ans, int arr[], int n) {
    // Base case: reached the end of the array
    if(index == n){
        ans.push_back(sum); // store the current subset sum
        return;
    }

    // Include the current element in the subset
    subsetsum(index + 1, sum + arr[index], ans, arr, n);

    // Exclude the current element from the subset
    subsetsum(index + 1, sum, ans, arr, n);
}

int main(){
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans;  // to store all subset sums
    int index = 0;
    int sum = 0;

    // Generate all subset sums
    subsetsum(index, sum, ans, arr, n);

    // Sort the subset sums in increasing order
    sort(ans.begin(), ans.end());

    // Print all subset sums
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
