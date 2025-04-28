#include <iostream>
using namespace std;

void totalwater_trapped(int height[], int n) {
    int left[10000];
    int right[10000];

    // Initialize: no bar to the left of first and right of last
    left[0] = 0;
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], height[i - 1]);
    }

    right[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], height[i + 1]);
    }

    /*
    Visualization of heights:
        |
      6 |       #
      5 | #     #       #
      4 | #     #       #
      3 | #     #   #   #
      2 | # #   #   #   #
      1 | # #   #   # # #
      0 +-----------------
          0 1 2 3 4 5 6

    Array:      4 2 0 6 3 2 5

    Water gets trapped in "valleys" (low points between high bars).
    At each index, the water level = min(leftMax, rightMax)
    Water stored = min(left[i], right[i]) - height[i]
    */

    int totalwater = 0;
    for (int i = 0; i < n; i++) {
        int currentwater = min(left[i], right[i]) - height[i];
        if (currentwater > 0) {
            totalwater += currentwater;
        }
    }

    cout << "Total water trapped is: " << totalwater << endl;
}

int main() {
    int height[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(height) / sizeof(height[0]);
    totalwater_trapped(height, n);
    return 0;
}
