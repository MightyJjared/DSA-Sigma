#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) { // constructor
        data = val;
        prev = next = NULL;
    }
};

class doubleList{
    Node* head;
    Node* tail;

public:
    doubleList(){ // constructor
        head = NULL;
        tail = NULL;
    }

    void insertatfirst(int val){
        Node* newnode = new Node(val); // node is creates with val as data and next as pointer
        if(head == NULL){
            head = tail = newnode;
        }
        else{
            newnode -> next = head;
            head -> prev = newnode;
            head = newnode;
        }
    }

    void deleteatfirst(){
        if(head == NULL){
            cout << "List is empty\n";
            return;
        }
        Node* collectnode = head;
        head = head -> next;
        head -> prev = NULL;
        collectnode -> next = NULL;
        delete collectnode;
    }
    void printlist(){
        Node* temp = head; 
        
        while(temp != NULL){
            cout << temp -> data << " <-> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};

int main(){
    doubleList l1;
    l1.insertatfirst(20);
    l1.insertatfirst(30);
    l1.deleteatfirst();
    l1.printlist();
    return 0;
}