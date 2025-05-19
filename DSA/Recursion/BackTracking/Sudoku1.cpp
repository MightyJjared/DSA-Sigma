#include <iostream>
using namespace std;

// print one solution
void print_board(int board[][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int board[][9], int row, int col, int digit){
    int n = 9;

    // Check row
    for(int j = 0; j < n; j++){
        if(board[row][j] == digit){
            return false;
        }
    }

    // Check column
    for(int i = 0; i < n; i++){
        if(board[i][col] == digit){
            return false;
        }
    }

    // Check 3x3 grid
    int startrow = (row / 3) * 3;
    int startcol = (col / 3) * 3;
    for(int i = startrow; i <= startrow + 2; i++){
        for(int j = startcol; j <= startcol + 2; j++){
            if(board[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int board[][9], int row, int col){
    // Base case: finished all rows
    if(row == 9){
        print_board(board);
        return true;
    }

    // Move to next row if column ends
    if(col == 9){
        return solveSudoku(board, row + 1, 0);
    }

    // Skip filled cells
    if(board[row][col] != 0){
        return solveSudoku(board, row, col + 1);
    }

    // Try placing digits 1 to 9
    for(int digit = 1; digit <= 9; digit++){
        if(isSafe(board, row, col, digit)){
            board[row][col] = digit;
            if(solveSudoku(board, row, col + 1)){
                return true;
            }
            board[row][col] = 0; // backtrack
        }
    }

    return false; // No valid digit found
}

int main(){
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Solved Sudoku:\n";
    solveSudoku(board, 0, 0);

    return 0;
}
