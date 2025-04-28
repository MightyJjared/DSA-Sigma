#include <iostream>
#include <vector>
using namespace std;

// We are finding the first occurene of a number in a vector

int firstoccurence(vector<int> vec, int target, int idx){
    if(idx == vec.size()){
        return false;
    }
    if(vec[idx] == target){
        return idx;
    }
    return firstoccurence(vec, target , idx+1);
}
int main(){
    vector<int> vec = {4,6,1,7,7,3};
    int target = 9;
    int result = firstoccurence(vec, target,0);
    cout << result << endl;
    return 0;
}