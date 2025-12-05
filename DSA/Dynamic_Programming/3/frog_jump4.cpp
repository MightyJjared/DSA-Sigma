#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Time Complexity: O(n * k)  
//   → For each index, we try up to k jumps, and each state is solved once.
// Space Complexity: O(n) 
//   → dp array + recursion stack.


// Memoization
/*
    Problem Reference: Coding Ninjas – "Frog Jump with K Jumps"
    ------------------------------------------------------------
    Question:
      You are given an array 'heights' of size 'n' where heights[i] 
      represents the height of the i-th stone. A frog starts at stone 0 
      and wants to reach stone n-1. From stone i, the frog can jump to 
      any of the next 'k' stones (i+1, i+2, ..., i+k), if within bounds.
      Cost of a jump = absolute difference in heights between the starting 
      and destination stones.

    Goal:
      Find the minimum total cost for the frog to reach the last stone.

    Note:
      This is the NEXT LEVEL of the classic Frog Jump problem 
      (where the frog could only jump 1 or 2 steps). 
      Here, the frog can jump up to 'k' steps ahead.
*/

int helper(int idx, vector<int> &heights, vector<int> &dp, int k){
    if(idx == 0){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }
    int minSteps = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(idx - i >= 0){
            int current = helper(idx - i, heights, dp, k) + abs(heights[idx] - heights[idx-i]);
            minSteps = min(current, minSteps); 
        }
    }
    return dp[idx] = minSteps;
}

int frogJump(int n, vector<int> &heights, int k){
    vector<int> dp(n, -1);  // only need size n
    return helper(n-1, heights, dp, k); 
}

int main() {
    int n = 4;
    int k = 4;
    vector<int> heights = {10,20,30,50};

    cout << frogJump(n, heights, k) << endl;
    return 0;
}
