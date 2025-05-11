#include <iostream>
#include <string>
using namespace std;

// its the same question as Gridways1 but here it also prints the ways we took to reach
// the destination with R as right and D as down.

int totalways(int row, int col, int n, int m, string ans){
    if(row == n-1 && col == m-1){ // 1 base case, reached destination
        cout << ans << endl;
        return 1;
    }

    if(row >= n || col >= m){ // 2 bas case where we dont go outside boundry of n and m
        return 0;
    }
    // right choice
    int val1 = totalways(row,col+1,n,m,ans+'R');

    // left choice
    int val2 = totalways(row+1,col,n,m,ans+'D');

    return val1 + val2;
}
int main(){
    int n = 3;
    int m = 3;
    string ans = "";
    int result = totalways(0,0,n,m,ans);
    cout << result << endl;
    return 0;
}
