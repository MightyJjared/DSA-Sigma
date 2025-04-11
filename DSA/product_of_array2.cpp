#include <iostream>
#include <vector>
using namespace std;

// Optimized approach using prefix and suffix arrays
vector<int> ProductArray(vector<int> nums) {         
    int n = nums.size();
    vector<int> ans(n, 1);    // Final result array
    vector<int> prefix(n, 1); // Prefix product array
    vector<int> suffix(n, 1); // Suffix product array

    // Compute prefix products (left side)
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Compute suffix products (right side)
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Multiply prefix and suffix to get the final result
    for (int i = 0; i < n; i++) {
        ans[i] = suffix[i] * prefix[i];
    }

    return ans;
}

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4};

    // Compute the product array
    vector<int> result = ProductArray(nums);

    // Print the result
    cout << "Product Array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
🔹 Example Walkthrough:

Input: nums = {1, 2, 3, 4}

Step 1: Compute prefix array:
prefix[i] = product of all elements before index i

    prefix[0] = 1  (no element before index 0)
    prefix[1] = 1 × 1  = 1
    prefix[2] = 1 × 2  = 2
    prefix[3] = 1 × 2 × 3 = 6

    Prefix: [1, 1, 2, 6]

Step 2: Compute suffix array:
suffix[i] = product of all elements after index i

    suffix[3] = 1  (no element after index 3)
    suffix[2] = 1 × 4 = 4
    suffix[1] = 4 × 3 = 12
    suffix[0] = 12 × 2 = 24

    Suffix: [24, 12, 4, 1]

Step 3: Compute final result:
result[i] = prefix[i] * suffix[i]

    result[0] = 1 × 24 = 24
    result[1] = 1 × 12 = 12
    result[2] = 2 × 4  = 8
    result[3] = 6 × 1  = 6

Output:
Product Array: 24 12 8 6
*/
