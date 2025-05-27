#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    // ❓ Problem: For each element in the array, find the **next greater element to its right**.
    // If no such element exists, store -1.
    //
    // 📘 Example:
    // arr = [100, 40, 80, 90, 90, 60, 100]
    // Output = [-1, 80, 90, -1, -1, 100, -1]
    // - For 100 → no greater element on right → -1
    // - For 40 → next greater is 80
    // - For 80 → next greater is 90
    // - For 90 → no greater on right → -1
    // - etc.

    vector<int> arr = {100, 40, 80, 90, 90, 60, 100};
    vector<int> ans(arr.size(), 0); // to store the result
    stack<int> s; // stores indices of potential next greater elements

    // 🔁 Traverse from right to left
    for(int i = arr.size()-1; i >= 0; i--){
        // ⚖️ Remove all smaller or equal elements from stack
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }

        // 📌 If stack is empty, no greater element to the right → store -1
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = arr[s.top()]; // top of stack is next greater element
        }

        s.push(i); // 🧱 Push current index to stack
    }

    // 🖨️ Print the result
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
