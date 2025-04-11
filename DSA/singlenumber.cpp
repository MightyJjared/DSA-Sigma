#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {4,6,9,3,98};

    vec.push_back(24);
    vec.pop_back();
    cout << vec.at(2) << endl;
    cout << vec.front() << endl;
    cout << vec.max_size() << endl;

    for(int val : vec){
        cout << val << endl;
    }
    return 0;
}