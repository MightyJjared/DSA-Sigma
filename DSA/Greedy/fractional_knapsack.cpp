/*
📌 Problem: Fractional Knapsack

You are given 'n' items, where each item has a value and a weight.
You are also given a knapsack of capacity 'W'.

Your task is to maximize the total value you can put into the knapsack.
Unlike the 0/1 Knapsack problem, you can take **fractions of items**.

✅ Input:
- Two arrays: `value[]` and `wt[]` of size `n`, where:
  - `value[i]` is the value of the i-th item
  - `wt[i]` is the weight of the i-th item
- Integer `W` → the maximum weight the knapsack can carry

✅ Output:
- The **maximum value** that can be obtained by putting items (or fractions) in the knapsack.

💡 Approach:
- Calculate value/weight ratio for each item
- Sort items by this ratio in descending order
- Take items greedily: full if possible, otherwise take the remaining weight as a fraction

Example:
Input:  value[] = {60, 100, 120}, wt[] = {10, 20, 30}, W = 50  
Output: Maximum value = 240

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// Comparator to sort items by value/weight ratio in descending order
bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first;
}

// Function to solve the fractional knapsack problem
int fractional_knapsack(vector<int> value, vector<int> wt, int weight){
    int n = value.size();  // Number of items

    // Store value/weight ratio and index for each item
    vector<pair<double, int>> ratio(n, make_pair(0, 0));
    for(int i = 0; i < n; i++){
        ratio[i].first = (double)value[i] / wt[i]; // value per unit weight
        ratio[i].second = i; // original index
    }

    // Sort items in descending order of ratio
    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0; // Total value accumulated in the knapsack

    // Traverse sorted items
    for(int i = 0; i < n; i++){
        if(weight == 0){
            return ans; // knapsack full
        }

        int idx = ratio[i].second;

        if(wt[idx] <= weight){
            // If item fits completely, take it
            ans += value[idx];
            weight -= wt[idx];
        }
        else{
            // Take the fraction of the item that fits
            ans += ratio[i].first * weight;
            weight = 0; // knapsack full
        }
    }

    return ans;
}

int main(){
    // Values and Weights of items
    vector<int> value = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int weight = 50; // Capacity of the knapsack

    // Output the result
    cout << "Maximum value = " << fractional_knapsack(value, wt, weight) << endl;

    return 0;
}
