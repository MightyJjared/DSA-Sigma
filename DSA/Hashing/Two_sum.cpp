#include <iostream>
#include <unordered_map>
using namespace std;

/*
Two Sum Problem
-----------------------------------------------------------
Question:
Given an array and a target, find two indices whose values sum to the target.

Example:
arr = [1, 2, 7, 11, 15, 9, 5], target = 9
Correct answer: indices (1, 2) because 2 + 7 = 9.

Approach (O(n)):
Use an unordered_map<int,int> to store {value -> index} for elements seen so far.
For each arr[i], compute complement = target - arr[i].
If complement exists in the map, print its stored index and i; otherwise store arr[i] -> i.
*/


void TwoSum(int arr[], int size, int target){
    unordered_map<int, int> m; // key = arr[i], value = index or i
    for(int i =0; i< size; i++){
        int component = target - arr[i]; 
        if(m[component] == 1){
            cout << "indexs = " << m[component] << "," << i << endl;
            break;
        }
        m[arr[i]] = i; // else adding the key and value to map
    }
}

int main(){
    int arr[] = {1,2,7,11,15,9,5};
    int size = 7;
    int target = 9;    
    
    TwoSum(arr, size, target);
    return 0;
}