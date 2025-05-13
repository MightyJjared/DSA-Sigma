#include <iostream>
#include <vector>
using namespace std;

// it is same as subsequence2 but instead we are just print the count of subsequences whose sum is 3
int subsequence(int arr[], int n, int index, vector<int> &ans, int sum) {
    if (index == n) {
        if (sum == 3) {
           return 1;
        }
        return 0;
    }

    // Include the current element
    ans.push_back(arr[index]);
    int countwith = subsequence(arr, n, index + 1, ans, sum + arr[index]);

    // Exclude the current element
    ans.pop_back();
    int countwithout = subsequence(arr, n, index + 1, ans, sum);
    return countwith + countwithout;
}

int main() {
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    cout << subsequence(arr, n, 0, ans, 0) << endl;  // initial sum is 0
    return 0;
}
