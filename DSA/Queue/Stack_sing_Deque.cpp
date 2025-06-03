#include <iostream>
#include <deque>
using namespace std;

// implenting a stack using deque specific functions
class Stack{
    deque<int> deq;
    public:
    void push(int val){
        deq.push_front(val);
    }

    void pop(){
        deq.pop_front();
    }

    int top(){
        return deq.front();
    }

    bool empty(){
        return deq.empty();
    }
};
int main(){
    Stack s;
    for(int i =1; i<= 5; i++){
        s.push(i);
    }

    while(!s.empty()){
        cout <<s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}