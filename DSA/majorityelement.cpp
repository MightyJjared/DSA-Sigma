#include <iostream>
#include <vector>
using namespace std;
// brute approach
int majorityElement(vector<int> nums){
    int n = nums.size();

    for(int val : nums){
        int freq = 0;
        for(int el : nums){
            if(val == el){
                freq ++;

            }
        }
        if (freq > n/2){
            return val;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {4,2,2,2,4};
    int result = majorityElement(nums); 
    cout << result << endl;
    return 0;
}