#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursive
// Striver dp playlist
// Ninja Training Problem:
// You have `n` days and 3 tasks each day. Each task gives certain points.
// You cannot perform the same task on consecutive days. Find the maximum total points you can earn.
// Example: points = {{2,1,3},
//                    {3,4,6},
//                   {10,1,6},
//                    {8,3,7}}
// One optimal sequence: Day0-task0(2) -> Day1-task2(6) -> Day2-task0(10) -> Day3-task2(7) = Total 25 points


class Solution {
public:
    int helper(int day, int last, vector<vector<int>> &points){
        if(day == 0){
            int maxi = 0;
            for(int task =0; task < 3; task++){
                if( task != last){
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxi =0;
        for(int task =0; task< 3; task++){
            if(task != last){
                int current_points = points[day][task] + helper(day-1, task, points);
                maxi = max(maxi, current_points);
            }
        }
        return maxi;
    }

    int ninjaTraining(int n, vector<vector<int>> &points) {
        return helper(n-1, 3, points);
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
