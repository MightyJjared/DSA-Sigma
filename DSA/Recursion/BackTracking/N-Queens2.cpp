#include <iostream>
#include <vector>
using namespace std;

// same question as N_queen1 but it only prints the first valid solutuion
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

bool queens(vector<vector<char>> &board, int row){
    int n = board.size();
    if(row==n){
        print(board);
        return true;
    }
    for(int j =0; j<n; j++){
        if (issafe(board,row,j)){
        board[row][j] = 'Q';
        if(queens(board, row+1) == true){
            return true;
        }
        board[row][j] = '.';
    }
}
return false;
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