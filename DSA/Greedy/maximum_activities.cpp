#include <iostream>
#include <vector>
using namespace std;

//it is called activity selection problem
//it is important that the end vector must be sorted in ascending order

int max_activity(vector<int> start, vector<int> end){
    int count = 1;
    int currentend = end[0];
    for(int i =1; i< start.size(); i++){
        if(currentend <= start[i]){
            count++;
            currentend = end[i];
        }
    }
    return count;
}

int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    cout << max_activity(start, end) << endl;
    return 0;
}