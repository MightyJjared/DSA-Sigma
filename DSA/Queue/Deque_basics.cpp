#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;

    dq.push_front(2); // 2
    dq.push_front(1); // 1 2

    dq.push_back(3); // 1 2 3
    dq.push_back(4); // 1 2 3 4

    dq.pop_front(); // 2 3 4
    dq.pop_back();  // 2 3

    while(!dq.empty()){
        cout << dq.front() << " "; // we also have back()
        dq.pop_front();            // we also have pop_back()
    }
    cout << endl;
    return 0;
}