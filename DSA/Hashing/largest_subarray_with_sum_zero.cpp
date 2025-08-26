#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
  Problem:
  --------
  Find the length of the longest subarray whose sum is zero in a given integer array.
  Given arr[], we want the maximum length L such that there exists indices i and j (i <= j)
  with arr[i] + arr[i+1] + ... + arr[j] == 0, and L = j - i + 1.

  Approach (detailed - prefix-sum + hashmap):
  -----------------------------------------
  1. Prefix sum idea:
     - Define prefixSum[k] = arr[0] + arr[1] + ... + arr[k].
     - The sum of subarray (j+1 .. i) equals prefixSum[i] - prefixSum[j].
     - If prefixSum[i] == prefixSum[j], then the subarray (j+1 .. i) has sum 0.

  2. Use a hashmap to store the earliest index where each prefix sum value appears:
     - unordered_map<int,int> m maps a prefix sum value -> earliest index at which that sum occurred.
     - While iterating the array, maintain a running sum `sum`.
       * If `sum` has never been seen before, record m[sum] = i (store earliest occurrence).
       * If `sum` has been seen before at index j = m[sum], then the subarray (j+1 .. i) sums to 0,
         and its length is current_len = i - j. Compare current_len with the maximum length found so far.
     - Why earliest index? Storing the earliest index produces the longest possible subarray when that prefix
       sum repeats later. Overwriting it with a later index would only give you shorter distances for future repeats.

  3. Edge case - subarray starting at index 0:
     - If sum == 0 at index i, then the subarray (0 .. i) sums to zero and its length is i+1.
     - A common trick to handle this uniformly is to initialize m[0] = -1 before the loop, so that when
       sum becomes 0 at index i, i - (-1) = i+1 gives the correct length. The current code does not initialize
       m[0] = -1, so it implicitly relies on detecting repeated sums only; if you want to simplify logic,
       consider initializing m[0] = -1 (this is a suggested improvement — code unchanged per your request).

  4. Complexity:
     - Time: O(n) on average (each element processed once, map operations average O(1)).
     - Space: O(n) in the worst case (storing distinct prefix sums in the map).

  5. Practical notes:
     - Use earliest occurrence to maximize subarray length.
     - For very large arrays or large element magnitudes, consider using a larger integer type (long long)
       for `sum` to avoid overflow.
     - If you need the start index as well as length, record both when updating the maximum.
     - This approach finds the maximum-length zero-sum subarray; it does not return its indices here
       (the function prints length). If no zero-sum subarray exists, the length remains 0.
*/

void largest_subarray(vector<int> arr){
    unordered_map<int, int> m;
    int current_max =0;
    int max_index = 0;
    int sum =0;
    for(int i=0; i< arr.size(); i++){
        sum += arr[i];
       
        if(m.count(sum) == 0){
            m[sum] = i;
        }
        else{
            current_max = i - m[sum];
            max_index = max(max_index, current_max);
        }
    }
    cout << "length = " << max_index << endl;
} 

int main(){
    vector<int> arr = {15,-2,2,-8,1,7,10};
    largest_subarray(arr);
    return 0;
}
