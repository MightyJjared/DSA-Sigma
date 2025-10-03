#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoization
// see strive playlist
class Solution {
public:
    int helper(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
        if(day == 0){
            dp[0][0] = max(points[0][1], points[0][2]);
            dp[0][1] = max(points[0][0], points[0][2]);
            dp[0][2] = max(points[0][0], points[0][1]);
            dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
            return dp[0][last];
        }

        if(dp[day][last] != -1){
            return dp[day][last];
        }

        int maxi =0;
        for(int task =0; task< 3; task++){
            if(task != last){
                int current_points = points[day][task] + helper(day-1, task, points, dp);
                maxi = max(maxi, current_points);
            }
        }
        return dp[day][last] = maxi;
    }

    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int> (4,-1));
        return helper(n-1, 3, points, dp);
    }
};

int main() {
    int n = 4;
    vector<vector<int>> points = {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8, 3, 7}
    };

    Solution sol;
    cout << sol.ninjaTraining(n, points) << endl;
    return 0;
}