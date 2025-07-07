/*
📌 Problem: Maximum Length of Pair Chain

You are given `n` pairs of numbers (a, b), where **a < b**.  
Each pair represents an interval. You can form a chain of these pairs such that:

👉 For any two pairs (a, b) and (c, d) in the chain,  
    **b < c** (the second element of the first pair is less than the first element of the next pair).

Your task is to find the **maximum length of such a chain** you can make from the given list of pairs.

---

📥 Example:
Input pairs = {(5, 24), (39, 60), (5, 28), (27, 40), (50, 90)}

After sorting by end value:  
(5, 24), (5, 28), (27, 40), (39, 60), (50, 90)

Possible valid chain:
(5, 24) → (27, 40) → (50, 90)

✅ Output:
Max length = 3

---

💡 Approach:
This is a greedy problem similar to the **activity selection** problem.
- Sort all pairs by their **second value** (end time).
- Start with the first pair.
- Pick a pair only if its starting time is **greater than the end time** of the last selected pair.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator to sort by second value (end time)
bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

// Function to compute the maximum length of chain of pairs
void max_length(vector<pair<int, int>> pairs){
    int size = pairs.size();

    // Step 1: Sort the pairs by end time
    sort(pairs.begin(), pairs.end(), compare);

    int count = 1; // At least one pair can always be selected
    int current_end = pairs[0].second; // Initialize end time from first pair

    // Step 2: Traverse remaining pairs
    for(int i = 1; i < size; i++){
        // If the next pair starts after the current selected pair ends
        if(pairs[i].first > current_end){
            count++; // Include this pair
            current_end = pairs[i].second; // Update end time
        }
    }

    // Step 3: Output the result
    cout << "Max length = " << count << endl;
}

int main(){
    int n = 5;

    // Initialize vector of pairs with n elements
    vector<pair<int, int>> pairs(n, make_pair(0, 0));

    // Input: Each pair has (start, end)
    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);

    // Call function to compute max length of chain
    max_length(pairs);

    return 0;
}
