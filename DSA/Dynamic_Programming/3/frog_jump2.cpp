#include <iostream>
#include <vector>
#include <cmath>   // for abs
#include <algorithm> // for min
using namespace std;

// tabulation

int frogJumpTab(int n, vector<int> &heights) {
    vector<int> dp(n, 0);

    // base case
    dp[0] = 0;

    // fill dp array iteratively
    for(int i = 1; i < n; i++){
        int second = INT16_MAX;
        int first = dp[i-1] + abs(heights[i] - heights[i-1]);
        if(i > 1){
            second = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(first, second);
    }

    return dp[n-1];
}

int main() {
    int n = 4;
    vector<int> heights = {10,20,30,10};

    cout << frogJumpTab(n, heights) << endl;
    return 0;
}
