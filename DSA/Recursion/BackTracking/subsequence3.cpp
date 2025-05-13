#include <iostream>
#include <vector>
using namespace std;

// it is same as subsequence1 bu instead we are just print the first subsequences whose sum is 3, not all whose
// sum is 3.
// ** important trick - if we want to print only first answer, and not the rest we just have to change the function
// to bool and add return true when base condition is met or and return false at the end of base condition
// and also add return true to how everytime we call a funtion recursively. Compare subsequence 2 and 3 to get 
// clear understanding.
bool subsequence(int arr[], int n, int index, vector<int> &ans, int sum) {
    if (index == n) {
        if (sum == 3) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
                cout << endl;
                return true;
        }
        return false;
    }

    // Include the current element
    ans.push_back(arr[index]);
    if(subsequence(arr, n, index + 1, ans, sum + arr[index])){
        return true;
    }

    // Exclude the current element
    ans.pop_back();
    if(subsequence(arr, n, index + 1, ans, sum)){
        return true;
    }
    
    return false;
}

int main() {
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    subsequence(arr, n, 0, ans, 0);  // initial sum is 0
    return 0;
}