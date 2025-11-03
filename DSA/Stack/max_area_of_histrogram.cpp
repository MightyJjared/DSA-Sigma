#include <iostream>
#include<vector>
#include <stack>
#include <algorithm>
using namespace std;

void print(vector<int> a){
    for(int i =0; i< a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void maxarea(vector<int> height){
    int n = height.size();
    vector<int> nextSmallerLeft(n) ;
    vector<int> nextSmallerRight(n) ;

    stack<int> s;
    // next smaller left approach

    for(int i =0; i< n;i++){
        while(s.size() > 0 && height[s.top()] >= height[i]){
            s.pop();
        }
        if(s.size() == 0){
           nextSmallerLeft[i] = -1;
        }
        else{
            nextSmallerLeft[i] = s.top();
        }
        s.push(i);
    }
    print(nextSmallerLeft);

    // next smaller right approach
    while(!s.empty()){ // emptying the stack or resetting
        s.pop();
    }

    for(int i = n-1; i >=0; i--){
        while(s.size() > 0 && height[s.top()] >= height[i]){
            s.pop();
        }
        if(s.size() == 0){
            nextSmallerRight[i] = n;
        }
        else{
            nextSmallerRight[i] = s.top();
        }
        s.push(i);
    }
    print(nextSmallerRight);

    // we alread have height , width = right - left -1
    int maximumarea = 0;
    for(int i =0; i< n; i++){
        int width = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
        int heights = height[i];
        int area = heights * width;
        maximumarea = max(maximumarea, area);
    }
    cout << "Maxarea is : " << maximumarea << endl;

}

int main(){
    vector<int> height = {2,1,5,6,2,3};
    maxarea(height);
    return 0;
}