#include <iostream>
using namespace std;

// prints all solutions

int solutionCount = 0;

void print_board(int board[][9]){
    cout << "Solution " << ++solutionCount << ":\n";
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------\n";
}

bool isSafe(int board[][9], int row, int col, int digit){
    int n = 9;

    // Row check
    for(int j = 0; j < n; j++){
        if(board[row][j] == digit){
            return false;
        }
    }

    // Column check
    for(int i = 0; i < n; i++){
        if(board[i][col] == digit){
            return false;
        }
    }

    // 3x3 grid check
    int startrow = (row / 3) * 3;
    int startcol = (col / 3) * 3;
    for(int i = startrow; i < startrow + 3; i++){
        for(int j = startcol; j < startcol + 3; j++){
            if(board[i][j] == digit){
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(int board[][9], int row, int col){
    // Reached end of board
    if(row == 9){
        print_board(board);
        return;
    }

    // Move to next row if column ends
    if(col == 9){
        solveSudoku(board, row + 1, 0);
        return;
    }

    // Skip filled cells
    if(board[row][col] != 0){
        solveSudoku(board, row, col + 1);
        return;
    }

    // Try all digits
    for(int digit = 1; digit <= 9; digit++){
        if(isSafe(board, row, col, digit)){
            board[row][col] = digit;
            solveSudoku(board, row, col + 1);  // Continue without returning
            board[row][col] = 0; // Backtrack
        }
    }
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

    solveSudoku(board, 0, 0);

    if(solutionCount == 0){
        cout << "No solutions found.\n";
    } else {
        cout << "Total solutions: " << solutionCount << endl;
    }

    return 0;
}
