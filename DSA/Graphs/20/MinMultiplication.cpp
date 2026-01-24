#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// GFG Reference: Minimum Multiplications to reach End
//
// Time Complexity:  O(n * M)
// Space Complexity: O(M)
// where:
//   n = size of array "arr"
//   M = modulo space (100000)
// Explanation:
// BFS explores values in layers. Each multiplication costs 1 step,
// and modulo bounds state space to 0..99999 so BFS is optimal here.

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();

        // dist[] stores minimum steps to reach each number 0..99999
        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        queue<pair<int,int>> q; // (steps, currentValue)
        q.push({0, start});

        while(!q.empty()) {
            int steps = q.front().first;
            int current = q.front().second;
            q.pop();

            if(current == end) {
                return steps;
            }

            for(int i = 0; i < n; i++) {
                int next = (current * arr[i]) % 100000;
                int nextSteps = steps + 1;

                if(nextSteps < dist[next]) {
                    dist[next] = nextSteps;
                    q.push({nextSteps, next});
                }
            }
        }
        return -1;
    }
};

int main() {
    // sample test for VS Code
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    Solution s;
    int ans = s.minimumMultiplications(arr, start, end);
    cout << ans << endl;  

    return 0;
}
