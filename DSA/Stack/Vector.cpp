#include <iostream>
#include <vector>
using namespace std;

// Stack implementation using vector for integers
class Stack{
    vector<int> vec;
    public:
    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        int lastIndex = vec.size() - 1;
        return vec[lastIndex];
    }

    bool isEmpty(){
        if (vec.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    while(!s1.isEmpty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    return 0;
}