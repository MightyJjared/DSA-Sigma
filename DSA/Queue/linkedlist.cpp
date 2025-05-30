#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    public:
    Queue() {
        head = tail = NULL;
    }

    void push(int val){ // insert at last
        Node* newnode = new Node(val);
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
        Node* temp = head;
        head = head -> next;
        delete temp;
    }

    int front(){
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
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}