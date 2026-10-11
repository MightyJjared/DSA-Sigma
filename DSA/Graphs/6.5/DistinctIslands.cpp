// GFG: Count Distinct Islands

// Approach:
// Traverse every cell using BFS. When we find an unvisited island,
// store the positions of its cells relative to the starting cell.
// This gives each island a shape. Store these shapes in a set,
// so identical island shapes are counted only once.

// Time: O(N*M log(N*M))
// Space: O(N*M)

class Solution {
  public:
    void bfs(int row, int col, set<vector<pair<int, int>>> &s, vector<vector<bool>> &visited, vector<vector<char>>& grid, int n, int m){
        queue<pair<int, int>> q;
        q.push({row, col});
        
        vector<pair<int, int>> vec;
        int VecRow[] = {-1, 0, 0, 1};
        int VecCol[] = {0, -1, 1, 0};
        
        int baseRow = row;
        int baseCol = col;
        
        visited[row][col] = true;
        
        while(q.size() > 0){
            int currentrow = q.front().first;
            int currentcol = q.front().second;
            
            q.pop();
            
            int frow = currentrow - baseRow;
            int fcol = currentcol - baseCol;
            
            vec.push_back({frow, fcol});
            
            for(int i =0; i < 4; i++){
                int nextrow = currentrow + VecRow[i];
                int nextcol = currentcol + VecCol[i];
                
                if(nextrow >= 0 && nextrow < n && nextcol >= 0 && nextcol < m 
                && visited[nextrow][nextcol] == false && grid[nextrow][nextcol] == 'L'){
                    visited[nextrow][nextcol] = true;
                    q.push({nextrow, nextcol});
                }
            }
        }
        s.insert(vec);
    }
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        set<vector<pair<int, int>>> s;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i =0; i < n; i++){
            for(int j =0; j < m; j++){
                if(visited[i][j] == false && grid[i][j] == 'L'){
                    bfs(i, j, s, visited, grid, n, m);
                }
            }
        }
        return s.size();
    }
};
