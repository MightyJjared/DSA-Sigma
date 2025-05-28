#include <iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node(T val){
        data = val;
        next = NULL;
    }
};

template<class T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    public:
    Queue() {
        head = tail = NULL;
    }

    void push(T val){ // insert at last
        Node<T>* newnode = new Node<T>(val);
      if(head == NULL){
        head = tail = newnode;
      }
      else{
      tail -> next = newnode;
      tail = newnode;
      }
    }

    void pop(){
        if(empty()){
            cout << "Queue is empty.\n";
            return;
        }
        Node<T>* temp = head;
        head = head -> next;
        delete temp;
    }

    T front(){
        if(empty()){
            cout << "Queue is empty.\n";
            return -1;
        }
        return head -> data;
    }

    bool empty(){
        return head == NULL;
    }
};

int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    Queue<char> q1;
    q1.push('a');
    q1.push('b');
    q1.push('c');
    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
    return 0;
}