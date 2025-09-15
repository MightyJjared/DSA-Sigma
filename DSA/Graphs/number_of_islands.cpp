#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode 200: Number of Islands
--------------------------------
Problem:
Given a 2D grid of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically.

Approach (DFS + Visited Matrix):
--------------------------------
1. Traverse each cell of the grid.
2. When we find a '1' that is not visited → it means a new island starts here.
3. Perform DFS to mark all connected '1's as visited.
4. Increment the island count.
5. Continue until the full grid is traversed.

Why DFS over BFS?
-----------------
Both work, but DFS is simpler to implement recursively for connected component problems,
while BFS would need an explicit queue. DFS explores one full island before moving on.

Time Complexity: O(N * M)  
Space Complexity: O(N * M) due to visited matrix
*/

class Solution {
public:
    void dfs(int row, int col, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &visited){
        visited[row][col] = true;
        
        // up
        if(row-1 >=0 && !visited[row-1][col] && grid[row-1][col] == '1'){
            dfs(row-1, col, n, m, grid, visited);
        }
        
        // down
        if(row+1 < n && !visited[row+1][col] && grid[row+1][col] == '1'){
            dfs(row+1, col, n, m, grid, visited);
        }

        // left
        if(col-1 >= 0 && !visited[row][col-1] && grid[row][col-1] == '1'){
            dfs(row, col-1, n, m, grid, visited);
        }

        // right
        if(col+1 < m && !visited[row][col+1] && grid[row][col+1] == '1'){
            dfs(row, col+1, n, m, grid, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i =0; i< n; i++){
            for(int j =0; j <m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(i,j,n,m,grid,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << sol.numIslands(grid) << endl;
    return 0;
}
