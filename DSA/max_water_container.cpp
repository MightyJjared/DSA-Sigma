#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the maximum area of water that can be stored
    int maxArea(vector<int>& height) {
        int maxwater = 0;   // Variable to store maximum water area
        int n = height.size();
        int lp = 0, rp = n - 1;  // Left and right pointers

        // Two-pointer approach
        while (lp < rp) {
            int heights = min(height[lp], height[rp]);  // Choose the smaller height
            int width = rp - lp;                        // Calculate the width between the two lines
            int area = heights * width;                 // Compute the water area
            maxwater = max(maxwater, area);             // Update max area if new area is larger

            // Move the pointer pointing to the shorter height
            if (height[lp] < height[rp]) {
                lp++;  // Move left pointer to the right
            } else {
                rp--;  // Move right pointer to the left
            }
        }
        return maxwater;  // Return the maximum area found
    }
};

int main() {
    // Example input: Heights of vertical lines
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};  

    // Creating an instance of the Solution class
    Solution sol;

    // Calling the maxArea function and storing the result
    int result = sol.maxArea(height);

    // Printing the maximum water area
    cout << "Maximum Water Area: " << result << endl;  // Expected Output: 49

    return 0;
}
