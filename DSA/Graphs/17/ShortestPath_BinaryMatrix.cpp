#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Reference: LeetCode 1091 - Shortest Path in Binary Matrix
// here proach is apply nor mal bfs with dijkstras relaxtion condition also we are using queue here instead of
// priority queue because here the dist will always increase by 1 wherease in dijkstras the distance could have
// increased by anyhting depending on the weight

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int> (n, 1e9));
        distance[0][0] = 1;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        queue<pair<int, pair<int,int>>> q;
        q.push({1, {0,0}}); //(distance, (row,col))

        int r[8] = {-1,-1,-1,0,0,1,1,1};
        int c[8] = {-1,0,1,-1,1,-1,0,1};

        while(q.size() > 0){
            int totaldistance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

            if(row == n-1 && col == n-1){
                return totaldistance;
            }

            for(int i =0; i < 8; i++){
                int newRow = row + r[i];
                int newCol = col + c[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0){
                    if(distance[newRow][newCol] > distance[row][col] + 1){
                        distance[newRow][newCol] = distance[row][col] + 1;
                        q.push({distance[newRow][newCol], {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    // Sample test for VS Code
    vector<vector<int>> grid = {
        {0,1,0},
        {0,0,0},
        {1,0,0}
    };

    int result = obj.shortestPathBinaryMatrix(grid);
    cout << "Shortest Path: " << result << endl;

    return 0;
}
