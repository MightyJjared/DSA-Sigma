#include <iostream>
using namespace std;

void diagonalsum(int mat[][4], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Sum the primary diagonal elements (i == j)
            if (i == j) {
                sum += mat[i][j];
            }
            // Sum the secondary diagonal elements (j == n - i - 1)
            // Using 'else if' ensures we do not double count the center element for odd matrices
            else if (j == n - i - 1) {
                sum += mat[i][j];
            }
        }
    }
    cout << "Sum of diagonal matrix is: " << sum << endl;
}

int main() {
    // Example 4x4 matrix (square matrix)
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4, m = 4;  // n will always be equal to m for square matrices
    diagonalsum(mat, n, m);  // Call the diagonalsum function
    return 0;
}
