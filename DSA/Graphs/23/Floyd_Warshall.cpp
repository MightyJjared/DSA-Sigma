#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Floyd-Warshall Algorithm
Time Complexity:  O(n^3)
Space Complexity: O(n^2)   (for the dist matrix)

Reference: GeeksforGeeks — Floyd Warshall Algorithm
*/

class Solution {
  public:
    int floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // check for negative cycles
        for(int i = 0; i < n; i++){
            if(dist[i][i] < 0){
                return -1;
            }
        }

        return 0; // success
    }
};

int main() {
    int INF = 1e8;

    vector<vector<int>> dist = {
        {0,   5,  INF, 10},
        {INF, 0,  3,   INF},
        {INF, INF, 0,  1},
        {INF, INF, INF, 0}
    };

    Solution sol;
    int status = sol.floydWarshall(dist);

    if(status == -1){
        cout << "Negative cycle detected\n";
        return 0;
    }

    for(auto &row : dist){
        for(auto &x : row){
            if(x >= INF) cout << "INF ";
            else cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

