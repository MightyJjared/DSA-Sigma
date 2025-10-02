#include <iostream>
#include <vector>
#include <cmath>   // for abs
#include <algorithm> // for min
using namespace std;

// tabulation but space optimized

int frogJumpTab(int n, vector<int> &heights) {

    // base case
    int prev1 = 0;
    int prev2 = 0;

    // fill dp array iteratively
    for(int i = 1; i < n; i++){
        int second = INT16_MAX;
        int first = prev1 + abs(heights[i] - heights[i-1]);
        if(i > 1){
            second = prev2 + abs(heights[i] - heights[i-2]);
        }
        int current = min(first, second);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n = 4;
    vector<int> heights = {10,20,30,10};

    cout << frogJumpTab(n, heights) << endl;
    return 0;
}
