#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// leetcode 85
// striver dp 55 the largestRectangleArea function is copied exactly from leetocde 84 and the logic is simple
// for understanding see the video(it is short)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> Left (heights.size());
        vector<int> Right (heights.size());
        stack<int> s;
        // left
        for(int i =0; i< heights.size(); i++){
            while(s.size() >0 && heights[i] <= heights[s.top()]){
                s.pop();
            }
            if(s.size() == 0){
                Left[i] = -1;
            }
            else{
                Left[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        // right
        for(int i =heights.size()-1; i>= 0; i--){
            while(s.size() >0 && heights[i] <= heights[s.top()]){
                s.pop();
            }
            if(s.size() == 0){
                Right[i] = heights.size();
            }
            else{
                Right[i] = s.top();
            }
            s.push(i);
        }
        int maximumarea = 0;
        for(int i =0; i< heights.size(); i++){
            int width = Right[i] - Left[i] - 1;
            int height = heights[i];
            int area = height * width;
            maximumarea = max(maximumarea, area);
        }
        return maximumarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0);
        int maxi = 0;
        for(int i = 0; i < row; i++){
            for(int j =0; j < col; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else{
                    heights[j] += 1;
                }
            }
            maxi = max(maxi, largestRectangleArea(heights));
        }
        return maxi;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << s.maximalRectangle(matrix);
    return 0;
}

/*
Example output:
6
*/
