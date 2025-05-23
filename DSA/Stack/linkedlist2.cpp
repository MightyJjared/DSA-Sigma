#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node(T val){ // constructor
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack{
    Node<T>* head;
    
    public:    
    Stack(){
        head = NULL;
    }

    void push(T val){ // insert at first
        Node<T>* newnode = new Node<T>(val);
        if(head == NULL){
            head = newnode;
        }
        else{
            newnode -> next = head;
            head =  newnode;
        }
    }

    void pop(){
        if (head == NULL){
            cout << "stack is empty\n";
            return;
        }
        Node<T>* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    T top(){
        return head -> data;
    }

    bool isEmpty(){
        return head == NULL;
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