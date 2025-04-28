#include <iostream>
using namespace std;

// Brute-force approach: checks each element one by one
void bruteforce(int mat[][4], int n, int m, int target){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == target){
                cout << "Brute Force -> Target found at index: (" << i << ", " << j << ")" << endl;
                return;
            }
        }
    }
    cout << "Brute Force -> Target not found." << endl;
}

// Staircase search: optimized for matrices where rows and columns are sorted
void staircase(int mat[][4], int n, int m, int target){
    int endrow = n - 1, startcol = 0;

    // Start from bottom-left corner
    while(endrow >= 0 && startcol <= m - 1){
        if(mat[endrow][startcol] == target){
            cout << "Staircase -> Target found at index: (" << endrow << ", " << startcol << ")" << endl;
            return;
        }
        else if(target < mat[endrow][startcol]){
            endrow--;  // Move up
        }
        else{
            startcol++;  // Move right
        }
    }

    cout << "Staircase -> Target not found." << endl;
}

int main() {
    int mat[4][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    int n = 4, m = 4; 
    int target = 8;

    // You can call either one or both to compare
    bruteforce(mat, n, m, target);
    staircase(mat, n, m, target);

    return 0;
}
