#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Question:
Given an array of integers and a target value k, count the total number of subarrays 
whose sum equals k.

Approach:
We use a prefix sum + hashmap technique.
- Maintain a running sum of elements.
- For each index, check if (sum - k) exists in the map; if yes, it means a subarray 
  ending at current index has sum = k.
- Store frequency of each prefix sum in the hashmap to handle multiple cases.
This reduces the problem to O(n) time using prefix sum and hashmap.
*/

void k_sum(vector<int> arr, int k){
    unordered_map<int, int> m;
    int count = 0;
    int sum = 0;
    m[0] = 1;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        int x = sum - k;

        if(m.count(x) == 1){
            count += m[x];
        }
        if(m.count(sum) == 1){
            m[sum]++;
        }
        else{
            m[sum] = 1;
        }
    }
    cout << count << endl;
}

int main(){
    vector<int> arr = {1,2,3};
    int k = 3;
    k_sum(arr,k);
    return 0;
}
