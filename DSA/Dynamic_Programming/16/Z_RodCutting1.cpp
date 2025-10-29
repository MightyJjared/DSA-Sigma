#include <iostream>
#include <vector>
using namespace std;

// recursive
/*
🔹 Problem: Rod Cutting (Striver DP 24)
🔹 LeetCode Reference: Similar to "Unbounded Knapsack" problem

Problem Explanation:
- You are given a rod of length 'n' and an array 'price[]' of size 'n'.
- price[i] represents the price of a rod piece of length i+1.
- You can cut the rod into smaller lengths and sell the pieces.
- Goal: Maximize total profit.

Example:
n = 4
price = {2, 5, 7, 8}

- One way to cut: [1,1,1,1] → profit = 2+2+2+2 = 8
- Another way: [2,2] → profit = 5+5 = 10 ✅
- Max profit = 10

Observation:
- This is an **Unbounded Knapsack problem** because you can use each length multiple times.

*/

class Solution {
public:
    int helper(int index, int N, vector<int> &price) {
        if(index == 0){
            return N * price[0];
        }
        int rod_length = index+1; // rod_lenght = W

        int notPick = helper(index-1, N, price);

        int pick = -1e9;
        if(rod_length <= N){
            pick = price[index] + helper(index, N-rod_length, price);
        }

        return max(pick, notPick);
    }

    int cutRod(vector<int> &price, int N) {
        int index = price.size();
        return helper(index-1, N, price);
    }
};

int main() {
    Solution sol;

    // Example inputs (you can modify as needed)
    int N = 4; 
    vector<int> price = {2, 5, 7, 8};

    int result = sol.cutRod(price, N);
    cout << "Maximum Profit = " << result << endl;

    return 0;
}
