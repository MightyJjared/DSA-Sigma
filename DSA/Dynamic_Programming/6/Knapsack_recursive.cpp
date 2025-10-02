#include <iostream>
#include <vector>
using namespace std;

/*
 Question:
 ---------
 You are given 'n' items, each with a certain weight and value.
 You also have a knapsack (bag) with a maximum capacity 'W'.
 The goal is to select a subset of these items such that:
   - The total weight does not exceed 'W'
   - The total value is maximized
 Constraint: Each item can either be included once or not at all (0-1 choice).

 Logic (Recursive):
 ------------------
 At every item 'n', we have two choices:
   1. Exclude the item → move to next item with the same capacity.
   2. Include the item (only if its weight <= remaining capacity) →
        add its value + recursively solve for the reduced capacity and remaining items.
 We compare both options and take the maximum.

 Base cases:
   - If no items are left (n == 0) → return 0
   - If no capacity is left (W == 0) → return 0

 This forms the recurrence:
   knapsack(W, n) = max(
       knapsack(W, n-1),                     // exclude
       val[n-1] + knapsack(W-wt[n-1], n-1)   // include (if fits)
   )
*/

// Recursive function for 0-1 Knapsack
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    // Base case 1: no items left
    if (n == 0) {
        return 0;
    }
    // Base case 2: no capacity left
    if (W == 0) {
        return 0;
    }

    // Case 1: Otherwise, we have two choices:
    if (wt[n-1] <= W) {
      //  (a) Exclude the current item
      int exclude = knapsack(W, wt, val, n-1);

      //  (b) Include the current item (reduce capacity and add its value)
      int include = val[n-1] + knapsack(W - wt[n-1], wt, val, n-1);

      // Take the maximum of include and exclude
      return max(include, exclude);
    }

    // Case 2: If the weight of the current item is more than capacity,
    // we cannot include it. So just move to the next item.
    else{
      return knapsack(W, wt, val, n-1);
    }
    
}

int main() {
    // Example items
    vector<int> val = {60, 100, 120};   // values of items
    vector<int> wt  = {10, 20, 30};     // weights of items
    int W = 50;                         // maximum capacity of knapsack
    int n = val.size();                 // number of items

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}
