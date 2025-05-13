#include <iostream>
#include <vector>
using namespace std;


 // using arrays
// Recursive function to generate subsequences
#include <iostream>
#include <vector>
using namespace std;

void subsequence(int arr[], int n, int index, vector<int> &ans) {
    if (index == n) {
        // Base case: print the current subsequence using a normal for loop
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
         if(ans.size() == 0){
            cout << "{}";
        }
        cout << endl;
        return;
    }

    // Include the current element
    ans.push_back(arr[index]);
    subsequence(arr, n, index + 1, ans);

    // Exclude the current element
    ans.pop_back();
    subsequence(arr, n, index + 1, ans);
}

int main() {
    int arr[] = {3,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    subsequence(arr, n, 0, ans);
    return 0;
}

// using vectors
/*void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void subsequence(vector<int> arr, vector<int> ans) {
    if (arr.size() == 0) {
        printVector(ans);
        return;
    }

    int current = arr[0];
    arr.erase(arr.begin());  // Remove the first element

    // Include current element
    ans.push_back(current);
    subsequence(arr, ans);

    // Exclude current element
    ans.pop_back();  // Backtrack
    subsequence(arr, ans);
}

int main() {
    vector<int> arr = {3, 2, 1};
    vector<int> ans;
    subsequence(arr, ans);
    return 0;
}*/