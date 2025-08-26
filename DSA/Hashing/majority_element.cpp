#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void majority_element(vector<int> nums){
    unordered_map<int, int> m;
    for (int i =0; i< nums.size(); i++){
        if(m.count(nums[i]) == 1){
            m[nums[i]]++;
        }
        else{
            m[nums[i]] = 1;
        }
    }

    for(pair<int, int> i : m){
        if(i.second > nums.size()/3){
            cout << i.first << " ";
        }
    }
}

int main(){
    vector<int> nums = {1,3,2,5,1,3,1,5,1,3,3};
    majority_element(nums);
    cout << endl;
    return 0;
}