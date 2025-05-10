#include <iostream>
using namespace std;

// Question - Find the number of ways to reach from (0,0) to (n-1,m-1) in 
// a N*M grid. Allowed moves = right and down direction

/*
Grid (3x3):
                   // Assume the diagram as sudoko diagram but 3*3
(0,0) (0,1) (0,2) 
(1,0) (1,1) (1,2) 
(2,0) (2,1) (2,2)  

You have to go from (0,0) to (2,2) by only moving right or down.
This code calculates the total number of such unique paths.
*/

int totalways(int row, int col, int n, int m){
    if(row == n-1 && col == m-1){ // 1 base case, reached destination
        return 1;
    }

    if(row >= n || col >= m){ // 2 bas case where we dont go outside boundry of n and m
        return 0;
    }
    // right choice
    int val1 = totalways(row,col+1,n,m);

    // left choice
    int val2 = totalways(row+1,col,n,m);

    return val1 + val2;
}
int main(){
    int n = 3;
    int m = 3;
    int result = totalways(0,0,n,m);
    cout << result << endl;
    return 0;
}
