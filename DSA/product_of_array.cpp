#include <iostream>
#include <vector>
using namespace std;

// Brute force approach to compute product of array except self
vector<int> ProductArray(vector<int> nums) {         
    int n = nums.size();
    vector<int> ans(n, 1); // Initialize the result vector with 1

    // Iterate over each index and calculate product of all elements except itself
    for(int i = 0; i < n; i++) {
        int product = 1; // Stores product of all elements except nums[i]
        for(int j = 0; j < n; j++) {
            if(i != j) {  // Skip the current index element
                product = product * nums[j];
            }
        }
        ans[i] = product; // Store the computed product
    }
    return ans; // Return the resultant product array
}

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4};

    // Compute the product array
    vector<int> result = ProductArray(nums);

    // Print the result
    cout << "Product Array: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
🔹 Example Walkthrough:

Input:  nums = {1, 2, 3, 4}

Step-by-step calculation:

- For index 0 → Product of {2,3,4}  → 2 × 3 × 4 = 24
- For index 1 → Product of {1,3,4}  → 1 × 3 × 4 = 12
- For index 2 → Product of {1,2,4}  → 1 × 2 × 4 = 8
- For index 3 → Product of {1,2,3}  → 1 × 2 × 3 = 6

Output:
Product Array: 24 12 8 6
*/
