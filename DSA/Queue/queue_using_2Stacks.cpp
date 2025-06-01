#include <iostream>
#include <stack>
using namespace std;

// Implementing a queue usin 2 stacks
// Appproach whenever we push an element into stack first tranfer all the elements in stack(s1) to another stack(s2)
// then push your elemnt into s1 then tranfer all element from s2 back to s1;
class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int data){// O(n)

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){// O(1)
        s1.pop();
    }

    int front(){ //O(1)
        return s1.top();
    }

    bool empty(){
        return s1.empty();
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}