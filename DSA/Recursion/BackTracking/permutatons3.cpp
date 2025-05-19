#include <iostream>
#include <vector>
using namespace std;

// Generates all permutations by removing elements and building up a path (ds)
// same as permutations1 but using vectors
void permutations(vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
    if (arr.empty()) {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        int current = arr[i];
        ds.push_back(current);

        // Create a new array without the current element
        vector<int> temp = arr;
        temp.erase(temp.begin() + i);

        permutations(temp, ans, ds);
        ds.pop_back(); // backtrack
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> ds;

    permutations(arr, ans, ds);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
