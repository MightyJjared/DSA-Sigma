#include <iostream>
#include <vector>
#include <cmath>   // for abs
#include <algorithm> // for min
using namespace std;

// tabulation

int frogJumpTab(int n, vector<int> &heights, int k) {
    vector<int> dp(n, 0);

    // base case
    dp[0] = 0;

    // fill dp array iteratively
    for(int i = 1; i < n; i++){
        int minSteps = INT16_MAX;
        for(int j = 1; j <=k; j++){
            if(i-j >= 0){
                int current = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(minSteps, current); 
            }
        }
        dp[i] = minSteps;
    }

    return dp[n-1];
}

int main() {
    int n = 4;
    int k = 4;
    vector<int> heights = {10,20,30,10};

    cout << frogJumpTab(n, heights, k) << endl;
    return 0;
}