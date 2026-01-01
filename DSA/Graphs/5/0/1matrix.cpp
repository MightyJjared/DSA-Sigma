#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// leetcode 542
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> visited(n, vector<bool> (m, false));
        queue<pair<pair<int, int>, int>> q;

        for(int i =0; i < n; i++){
            for(int j =0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    visited[i][j] = true;
                }
            }
        }
        int delRow[] = {-1,0,0,1};
        int delCol[] = {0,1,-1,0};

        while(q.size() > 0){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;

            q.pop();

            for(int i =0; i < 4; i++){
                int nextrow = row + delRow[i];
                int nextcol = col + delCol[i];

                if(nextrow < n && nextrow >= 0 && nextcol <m && nextcol >= 0 && visited[nextrow][nextcol] == false){
                    mat[nextrow][nextcol] = distance+1;
                    visited[nextrow][nextcol] = true;
                    q.push({{nextrow, nextcol}, distance+1});
                }
            }
        }
        return mat;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 1}
    };

    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(mat);

    for(auto &row : ans){
        for(auto &x : row){
            cout << x << " ";
        }
        cout << endl;
    }
}
