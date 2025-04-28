/*
Leetcode 33: Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k 
(1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]].

Given the array nums after the possible rotation and an integer target, 
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i], target <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
*/

#include <iostream>
#include <vector>
using namespace std;

// User-defined function to implement O(log n) binary search in rotated sorted array
int search(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size()-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(target == arr[mid]){
            return mid;
        }
        if(arr[start] <= arr[mid]){
          if(arr[start] <= target && target < arr[mid]){
              end = mid-1;
          }
          else{
                start = mid+1;
              }
    }
        if (arr[mid] <= arr[end]){
            if (arr[mid] < target && target <= arr[end]){
                start = mid +1;
        }
            else{
            end = mid-1;
        }
    }
    return -1; // Placeholder return
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example input
    int target = 0;

    int index = search(nums, target);
    cout << "Index of target: " << index << endl;

    return 0;
}
