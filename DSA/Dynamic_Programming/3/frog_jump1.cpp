#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
// memoization
// Time Complexity: O(n)  -> each state computed once using memoization
// Space Complexity: O(n) -> dp array + recursion stack

/*
    Problem Reference: Coding Ninjas – "Frog Jump"
    -------------------------------------------------
    Question:
      You are given an array 'heights' of size 'n' where heights[i] 
      represents the height of the i-th stone. 
      A frog starts at stone 0 and wants to reach stone n-1. 
      From stone i, the frog can jump:
         - to stone i+1
         - to stone i+2
      Cost of a jump = absolute difference in heights between 
      the starting and destination stones.
    
    Goal:
      Find the minimum total cost for the frog to reach the last stone.

    Example:
    --------
    Input:
      n = 4
      heights = [10, 30, 40, 20]
    
    Explanation:
      - Start at stone 0 (height 10)
      - Possible paths:
          Path A: 0 → 1 → 2 → 3 
            Cost = |30-10| + |40-30| + |20-40|
                 = 20 + 10 + 20 = 50
          Path B: 0 → 2 → 3
            Cost = |40-10| + |20-40|
                 = 30 + 20 = 50
          Path C: 0 → 1 → 3
            Cost = |30-10| + |20-30|
                 = 20 + 10 = 30   <-- minimum
      Answer: 30

    Approach (Dynamic Programming):
      - Define dp[i] = minimum cost to reach stone i.
      - Transition:
           dp[i] = min(
                        dp[i-1] + abs(heights[i] - heights[i-1]),
                        dp[i-2] + abs(heights[i] - heights[i-2])  // if i > 1
                      )
      - Base case:
           dp[0] = 0   (already on first stone)
      - Answer = dp[n-1].
*/
int helper(int idx, vector<int> &heights, vector<int> &dp){
    if(idx == 0){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }
    int right = INT_MAX;
    int left = helper(idx-1, heights,dp) + abs(heights[idx] - heights[idx - 1]);

    if(idx > 1){
        right = helper(idx-2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
    }
    dp[idx] = min(left, right);
    return dp[idx];
}
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    return helper(n-1, heights, dp); 
}

int main() {
    int n = 4;
    vector<int> heights = {10,20,30,10};

    cout << frogJump(n, heights) << endl;
    return 0;
}
