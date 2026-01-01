#include <iostream>
#include <vector>
using namespace std;

// LeetCode 130: Surrounded Regions
// Problem:
// Capture all regions surrounded by 'X'.
// A region is captured if it is NOT connected to the boundary.

class Solution {
public:
    // DFS to mark all 'O's connected to the boundary
    void dfs(int row, int col,
             vector<vector<char>>& board,
             vector<vector<bool>>& visited,
             int n, int m) {

        visited[row][col] = true;

        // up
        if(row-1 >= 0 && board[row-1][col] == 'O' && visited[row-1][col] == false){
            dfs(row-1, col, board, visited, n, m);
        }

        // down
        if(row+1 < n && board[row+1][col] == 'O' && visited[row+1][col] == false){
            dfs(row+1, col, board, visited, n, m);
        }

        // left
        if(col-1 >= 0 && board[row][col-1] == 'O' && visited[row][col-1] == false){
            dfs(row, col-1, board, visited, n, m);
        }

        // right
        if(col+1 < m && board[row][col+1] == 'O' && visited[row][col+1] == false){
            dfs(row, col+1, board, visited, n, m);
        }
    }

    void solve(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();

        // visited[i][j] = true means this 'O' is connected to boundary
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        // Traverse first and last row
        for(int i = 0; i < col; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board, visited, row, col);
            }
            if(board[row-1][i] == 'O'){
                dfs(row-1, i, board, visited, row, col);
            }
        }

        // Traverse first and last column
        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, visited, row, col);
            }
            if(board[i][col-1] == 'O'){
                dfs(i, col-1, board, visited, row, col);
            }
        }

        // Flip all unvisited 'O' to 'X'
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

/*
Time Complexity:
- O(N × M)
  Each cell is visited at most once during DFS and final traversal.

Space Complexity:
- O(N × M)
  visited matrix + recursion stack in worst case.
*/

int main() {
    Solution sol;

    // Example board
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    sol.solve(board);

    // Print result
    for(auto &row : board){
        for(auto cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
