#include <iostream>
#include <vector>
using namespace std;

// it is same as subsequence1 bu instead we are just print the subsequences whose sum is 3
void subsequence(int arr[], int n, int index, vector<int> &ans, int sum) {
    if (index == n) {
        if (sum == 3) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            if (ans.size() == 0) {
                cout << "{}";
            }
            cout << endl;
        }
        return;
    }

    // Include the current element
    ans.push_back(arr[index]);
    subsequence(arr, n, index + 1, ans, sum + arr[index]);

    // Exclude the current element
    ans.pop_back();
    subsequence(arr, n, index + 1, ans, sum);
}

int main() {
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    subsequence(arr, n, 0, ans, 0);  // initial sum is 0
    return 0;
}
