#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tabulation
// see strive playlist
class Solution {
public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int> (4,-1));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                int maxi = 0;
                for(int task  =0; task < 3; task++){
                    if(task != last){
                        int current_point = points[day][task] + dp[day-1][task];
                        maxi = max(maxi, current_point);
                    }
                }
                dp[day][last] = maxi;
            }
        }
        return dp[n-1][3];
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