#include <iostream>
#include <queue>
using namespace std;

// Implementing a stack usin 2 queue
// Appproach whenever we push an element into queue first tranfer all the elements in queue(q1) to another queue(q2)
// then push your elemnt into q1 then tranfer all element from q2 back to q1;
class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int data){// O(n)

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){// O(1)
        q1.pop();
    }

    int top(){ //O(1)
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}