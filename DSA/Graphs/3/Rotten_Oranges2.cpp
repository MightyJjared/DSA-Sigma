#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
LeetCode 994: Rotting Oranges
--------------------------------
You are given an m x n grid where:
  0 → empty cell
  1 → fresh orange
  2 → rotten orange

Each minute, any fresh orange that is 4-directionally adjacent to a rotten one 
becomes rotten.

Return:
  - The minimum number of minutes until no cell has a fresh orange.
  - If impossible, return -1.
*/

class Solution {
public:
    class edge{
        public: 
        int row;
        int col;
        int time;
        edge(int row, int col, int time){
            this->row = row;
            this-> col = col;
            this -> time = time;
        }
    };

    int bfs(int rows, int cols, vector<vector<bool>> &visited, vector<vector<int>>& grid, int n, int m){
        queue<edge> q;
        visited[rows][cols] = true;
        int minute =0;
        q.push(edge(rows, cols, 0));

        while(q.size() > 0){
            edge e = q.front();
            q.pop();

            minute = max(minute, e.time);

            // up
            if(e.row-1 >= 0 && grid[e.row-1][e.col] == 1 && visited[e.row-1][e.col] == false){
                visited[e.row-1][e.col] = true;
                grid[e.row-1][e.col] =2;
                q.push(edge(e.row-1, e.col, e.time + 1));
            }

            // down
            if(e.row+1 < n && grid[e.row+1][e.col] == 1 && visited[e.row+1][e.col] == false){
                visited[e.row+1][e.col] = true;
                grid[e.row+1][e.col] =2;
                q.push(edge(e.row+1, e.col, e.time + 1));
            }
            
            // left
            if(e.col-1 >= 0 && grid[e.row][e.col-1] == 1 &&  visited[e.row][e.col-1] == false){
                visited[e.row][e.col-1] = true;
                grid[e.row][e.col-1] =2;
                q.push(edge(e.row, e.col-1, e.time + 1));
            }

            // right
            if(e.col+1 < m  && grid[e.row][e.col+1] == 1 && visited[e.row][e.col+1] == false){
                visited[e.row][e.col+1] = true;
                grid[e.row][e.col+1] =2;
                q.push(edge(e.row, e.col+1, e.time + 1));
            }
            
        }
        return minute;

    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        int minute = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i= 0; i< n; i++){
            for(int j =0; j <m ; j++){
                if(visited[i][j] == false && grid[i][j] == 2){
                    minute = max(minute, bfs(i, j, visited, grid, n, m));
                }
            }
        }
        
        for(int i =0; i < n; i++){
            for(int j =0; j< m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minute;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = sol.orangesRotting(grid);

    cout << "Result: " << result << endl;

    return 0;
}
