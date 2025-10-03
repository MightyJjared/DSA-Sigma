#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {
    // prev[task] = max points till previous day if we last did "task"
    // last = 0 -> task0 was last done
    // last = 1 -> task1 was last done
    // last = 2 -> task2 was last done
    // last = 3 -> no restriction (for initialization)
    vector<int> prev(4, 0);

    // Base case: Day 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    // From day 1 to n-1
    for(int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for(int last = 0; last < 4; last++) {
            int maxi = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi, point);
                }
            }
            curr[last] = maxi;
        }
        prev = curr;
    }

    return prev[3]; // no restriction on last day
}

int main() {
    int n = 4;
    vector<vector<int>> points = {
        {2,1,3},
        {3,4,6},
        {10,1,6},
        {8,3,7}
    };

    cout << ninjaTraining(n, points) << endl;
    return 0;
}
