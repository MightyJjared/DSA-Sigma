#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element using Moore’s Voting Algorithm
int MajorityElement(vector<int> nums) {
    int n = nums.size(); // Get the size of the array
    int freq = 0; // This keeps track of the frequency count of the candidate
    int ans = 0;  // This stores the potential majority element

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        if (freq == 0) {
            ans = nums[i]; // Set the current number as the potential majority element
        }
        // If nums[i] is the candidate, increase frequency, otherwise decrease
        if (ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }

    return ans; // Since a majority element is guaranteed, return the candidate
}

int main() {
    vector<int> nums = {3, 1, 3, 1, 1}; // Example input
    int result = MajorityElement(nums); // Call the function to get the majority element
    cout << result << endl; // Print the result
    return 0;
}
