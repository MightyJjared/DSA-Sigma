#include <iostream>
using namespace std;

void spiralmatrix(int mat2[][4], int n, int m) {
    int startrow = 0;
    int startcol = 0;
    int endrow = n - 1;
    int endcol = m - 1;

    /*
    ------------------------------------------
    🌀 SPIRAL MATRIX TRAVERSAL EXPLANATION 🌀
    ------------------------------------------
    A "Spiral Matrix" traversal means printing the elements
    of a 2D matrix in spiral order — moving around the matrix
    in layers: top → right → bottom → left, then inward.

    Example Input Matrix (3x4):
        [ 1   2   3   4 ]
        [ 5   6   7   8 ]
        [ 9  10  11  12 ]

    Spiral Traversal Diagram:
        [ T   T   T   R ]
        [ L           R ]
        [ L   B   B   B ]

        T = top row → (left to right)
        R = right column ↓ (top to bottom)
        B = bottom row ← (right to left)
        L = left column ↑ (bottom to top)

    Spiral Traversal Order:
        1 2 3 4 8 12 11 10 9 5 6 7

    🔸 EDGE CASE NOTE:
    The edge case checks are only needed when the matrix has:
      - an **odd number of rows** (e.g. 3x4)
      - or an **odd number of columns** (e.g. 4x3)
    Because the last inner layer might be a **single row or single column**,
    and we want to avoid printing it twice.

    Example:
        For a 3x3 matrix:
        [ 1  2  3 ]
        [ 4  5  6 ]
        [ 7  8  9 ]
        The center (5) should only be printed once.
    */

    while (startrow <= endrow && startcol <= endcol) {
        // Top Row → (left to right)
        for (int i = startcol; i <= endcol; i++) {
            cout << mat2[startrow][i] << " ";
        }

        // Right Column ↓ (top to bottom)
        for (int j = startrow + 1; j <= endrow; j++) {
            cout << mat2[j][endcol] << " ";
        }

        // Bottom Row ← (right to left)
        for (int i = endcol - 1; i >= startcol; i--) {
            if (startrow == endrow){
                break; 
            }// 🟠 Needed when only one row remains
            cout << mat2[endrow][i] << " ";
        }

        // Left Column ↑ (bottom to top)
        for (int j = endrow - 1; j >= startrow + 1; j--) {
            if (startcol == endcol){
                 break;
             } // 🟠 Needed when only one column remains
            cout << mat2[j][startcol] << " ";
        }

        // Move to inner spiral layer
        startrow++;
        startcol++;
        endrow--;
        endcol--;
    }
    cout << endl;
}

int main() {
    int mat2[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int n = 3, m = 4;

    spiralmatrix(mat2, n, m);

    return 0;
}

/*
---------------------------
🧾 OUTPUT of this program:
---------------------------
1 2 3 4 8 12 11 10 9 5 6 7
---------------------------
*/

