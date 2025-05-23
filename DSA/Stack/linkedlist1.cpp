#include <iostream>
#include <list>
#include <string>
using namespace std;

// stack implentation using linkedlist using STL library
template<class T>
class Stack{
    list<T> l1;
    
public:
    void push(T val){
        l1.push_front(val); // insert at first
    }

    void pop(){
        l1.pop_front(); // delete first node
    }

    T top(){
        return l1.front();
    }

    bool isEmpty(){
        return l1.size() == 0; // returns true if size is = 0
    }
};
int main(){
    Stack<int> s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);

    while(!s1.isEmpty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    return 0;
}