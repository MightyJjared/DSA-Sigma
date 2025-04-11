#include <iostream>
using namespace std;

void totalwater_trapped(int height[], int n){
    int left[10000];
    left[0] = INT16_MIN;
    for(int i =1;i<n;i++){
        left[i] = max(left[i-1], height[i-1]);
    }
    int right[10000];
    right[n-1] = INT16_MIN;
    for(int i = n-2;i>=0;i--){
        right[i] = max(right[i+1], height[i+1]);
    }

    int toatalwater = 0;
    for(int i=0;i<n;i++){
        int currentwater = min(left[i], right[i]) - height[i];
        if(currentwater > 0){
            toatalwater += currentwater;
        }
    }

    cout << "Total water trapped is : " << toatalwater << endl;

}
int main(){
    int height[] = {4,2,0,6,3,2,5};
    int n = sizeof(height)/sizeof(height[0]);
    totalwater_trapped(height, n);
    return 0;
}