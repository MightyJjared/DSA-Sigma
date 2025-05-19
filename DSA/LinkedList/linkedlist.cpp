#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val) { // constructor
        data = val;
        next = NULL;
    }

    ~Node(){ // destructor
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){ // constructor
        head = NULL;
        tail = NULL;
    }

    ~List(){ // destructor
        if(head != NULL){
        delete head;
        head = NULL;
    }
}

    void insertatfirst(int val){
        Node* newnode = new Node(val); // node is creates with val as data and next as pointer
        if(head == NULL){
            head = tail = newnode;
        }
        else{
            newnode -> next = head;
            head = newnode;
        }
    }

    void insertatlast(int val){
        Node* newnode = new Node(val); // node is creates with val as data and next as pointer
        if(head == NULL){
            head = tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
    }

    void printlist(){
        Node* temp = head; 
        
        while(temp != NULL){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }

    void insertatposition(int val, int pos){
        Node* newnode = new Node(val);
        Node* temp = head;

        for(int i =0; i< pos-1;i++){// by the end of loop we will be at pos-1
            if(temp == NULL){
                cout << "Invalid position";
                return;
            }
            temp = temp ->next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }

    void deletefirstnode(){
        if(head == NULL){
            cout << " List is empty\n";
            return;
        }
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    void deletelastnode(){
        Node* temp = head;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    int search(int val){ // returns the idx for a given value and -1 if not found
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp -> data == val){
                return idx;
            }
            temp = temp -> next;
            idx++;
        }
        return -1;
    }
    int helper1(Node*head, int val){ // 1 way to search using recursion with helper 1
        if(head == NULL){
            return -1;
        }
        if(head ->data == val){
            return 0;
        }
        int idx = helper1(head->next,val);
        if(idx == -1){
            return -1;
        }
        return idx +1;
    }

    int searchrecursive1(int val){
        return helper1(head,val);
    }

    int helper2(Node* head, int val, int idx) { // 2 wayy to search recursively usinh helper2
        if(head == NULL) return -1;
        if(head->data == val) return idx;
        return helper2(head->next, val, idx + 1);
    }
    
    int searchrecursive2(int val) {
        return helper2(head, val, 0); // Start from index 0
    }

    void reverse(){ // approach - we will use 3 pointers prev, current and next to reverse.
        Node* prev = NULL;
        Node* current = head;

        while(current != NULL){
            Node* next = current -> next;
            current -> next = prev;

            prev = current;
            current = next;
        }
        head = prev;
    }

    int getsize(){
        Node* temp = head;
        int size =0;
        while(temp != NULL){
            temp = temp -> next;
            size++;
        }
        return size;
    }

    void removeNthNode(int n){  // removing n th node from the end where last node is n=1
        int size = getsize();
        Node* prev = head;
        for(int i =1; i < (size-n); i++){ // (size-n) gives the node befoe the n th node from the start
            prev = prev-> next;
        }
        Node* todelete = prev-> next;
        prev -> next = prev -> next -> next;
        todelete -> next = NULL;
        delete todelete;
    }
    
};

int main(){
    List l1;
    l1.insertatfirst(20);
    l1.insertatfirst(10);
    l1.insertatlast(30);
    l1.insertatposition(25,2); // position is starting from 0 not 1
    //l1.deletefirstnode();
    //l1.deletelastnode();
    l1.printlist();
    //cout << l1.searchrecursive1(25) << endl;
    //l1.reverse();
    l1.removeNthNode(2);
    l1.printlist();
    return 0;
}