#include <iostream>
#include <vector>
using namespace std;

// We are finding the last occurene of a number in a vector
// 🎯 Summary in One Line:
// We go to the end first so that we don’t miss a later occurrence;
// then we check backward to find the last matching index.

int lastoccurence(vector<int> vec, int target, int i){
    if(i == vec.size()){
        return -1;
    }

    int idx = lastoccurence(vec, target , i+1);
    if (idx == -1){
        if(vec[i] == target){
            return i;
        }
    }
    return idx;
}
int main(){
    vector<int> vec = {4,6,1,7,7,7,3};
    int target = 7;
    int result = lastoccurence(vec, target,0);
    cout << result << endl;
    return 0;
}