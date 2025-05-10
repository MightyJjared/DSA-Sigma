#include <iostream>
#include <vector>
using namespace std;
 
// Question - Find and print all possible ways to place N queenson an N*N chess board such that
// no 2 queens can attack each other
void print(vector<vector<char>> &board){
    int n = board.size();
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "-----------" << endl;
}

bool issafe(vector<vector<char>> &board, int row, int col){
    int n = board.size();
    // horizontal safety
    for(int i=0; i<n;i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

     // vertical safety
     for(int i=0; i<n;i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

     //left diagonal
     for(int i=row, j = col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    //right diagonal
    for(int i=row, j = col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void queens(vector<vector<char>> &board, int row){
    int n = board.size();
    if(row==n){
        print(board);
        return;
    }
    for(int j =0; j<n; j++){
        if (issafe(board,row,j)){
        board[row][j] = 'Q';
        queens(board, row+1);
        board[row][j] = '.';
    }
}
}

int main(){
    vector<vector<char>> board;
    int n = 4;
    for(int i=0;i<n;i++){
        vector<char> newrow;
        for(int j=0; j<n;j++){
            newrow.push_back('.');
        }
        board.push_back(newrow);
    }
    queens(board,0);
    return 0;
}




