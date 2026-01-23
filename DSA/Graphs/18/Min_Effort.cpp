#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// LeetCode reference: Minimum Effort Path (Dijkstra approach)
// This  is striver graph lecture 37 it is a bit on not normal side so for intution check the video
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Part 1 Declarations
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;

        // Type is min heap will store ((distance), (row,col))
        priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
        > pq;

        int r[] = {-1,0,0,1};
        int c[] = {0,-1,1,0};

        // Part 2 Pushing values 
        pq.push({0, {0, 0}});

        // Part 3 Applying dijkstras
        while(pq.size() > 0){
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            // Checking if we have reached the last cell
            if(row == n-1 && col == m-1){
                if(effort >= dist[row][col]){ // here since it is min heap and this condition is true then we wont get a smaller final answer it will either be equal or greater
                    return dist[row][col];
                }
            }

            for(int i = 0; i < 4; i++){
                int nextrow = row + r[i];
                int nextcol = col + c[i];

                if(nextrow < n && nextrow >= 0 && nextcol < m && nextcol >= 0){// checking basic boundary conditions

                    int current_effort = abs(heights[row][col] - heights[nextrow][nextcol]); // calculating from heights array the abs difference
                    int maximum = max(effort, current_effort);

                    if(maximum < dist[nextrow][nextcol]){ // We will only push into queue only when we get someone whose value is smaller then the value of distance matrix
                        dist[nextrow][nextcol] = maximum;
                        pq.push({maximum, {nextrow, nextcol}});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    // Sample test for VS Code execution
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    Solution s;
    int ans = s.minimumEffortPath(heights);
    cout << ans << endl;

    return 0;
}
