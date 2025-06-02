#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// reversing a queue using a stack
void reverse(queue<int> &q){
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;
    for(int i =1; i<= 10; i++){
        q.push(i);
    }

    reverse(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}