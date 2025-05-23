#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Stack implementation using vector for any data types like int , char ,string, bool using template
template<class T>
class Stack{
    vector<T> vec;
    public:
    void push(T val){
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    T top(){
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
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    while(!s1.isEmpty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    Stack<char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    while(!s2.isEmpty()){
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    Stack<string> s3;
    s3.push("World");
    s3.push("Hello");
    while(!s3.isEmpty()){
        cout << s3.top() << " ";
        s3.pop();
    }
    cout << endl;

    return 0;
}