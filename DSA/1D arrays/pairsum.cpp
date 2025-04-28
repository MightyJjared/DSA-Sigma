#include <iostream>
#include <vector>
#include <algorithm>  // For sort (optional, for safety)
using namespace std;

// Condition given that it is sorted
// Brute-force approach
void PairSum(vector<int> vec, int target){
    for(int i = 0; i < vec.size(); i++){
        for(int j = i+1; j < vec.size(); j++){
            if(vec[i] + vec[j] == target){
                cout << "Pair found: (" << vec[i] << ", " << vec[j] << ")" << endl;
                return;
            }
        }
    }
    cout << "No pair found with sum = " << target << endl;
}

// Optimized approach (Two-pointer technique)
void PairSum2(vector<int> vec, int target){
    // Make sure the vector is sorted
    sort(vec.begin(), vec.end()); // Optional if you're unsure

    int start = 0;
    int end = vec.size() - 1;
    while(start < end){
        int sum = vec[start] + vec[end];
        if(sum == target){
            cout << "Optimized Pair found: (" << vec[start] << ", " << vec[end] << ")" << endl;
            return;
        }
        else if(sum > target){
            end--;
        }
        else{
            start++;
        }
    }
    cout << "No pair found with sum = " << target << " (Optimized)" << endl;
}

int main(){
    vector<int> vec = {2, 5, 7, 9};
    int target = 9;

    // You can test both
    PairSum(vec, target);
    PairSum2(vec, target);

    return 0;
}
