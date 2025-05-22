#include <iostream>
using namespace std;

// Node class definition
class Node{
    public:
    int data;
    Node* next;

    Node(int data) { // constructor
        this -> data = data;
        next = NULL;
    }
};

// Linked list class
class List{
public:
    Node* head;
    Node* tail;

    List(){ // constructor
        head = NULL;
        tail = NULL;
    }

    void insertatfirst(int val){
        Node* newnode = new Node(val); // node is created with val as data
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
};

Node* splitAtMid(Node * head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast -> next != NULL){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(prev != NULL){
        prev -> next = NULL;
    }
    return slow;
}

Node* reverse(Node* head){
    Node* current = head;
    Node* prev = NULL;

    while(current != NULL){
        Node* next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node* zigzag(Node* head){
    Node* righthead = splitAtMid(head);
    Node* rev_righthead = reverse(righthead);

    // merging alternatively

    Node* left = head;
    Node* right = rev_righthead;

    while(left != NULL && right != NULL){
        Node* nextleft = left -> next;
        left -> next = right;
        left = nextleft;

        if (left == NULL) break; // for odd linked list

        Node* nextright = right -> next;
        right -> next = left;
        right = nextright;
    }
    return head;
}

// Helper function to print the list 
void printlist(Node* head){
    Node* temp = head; 
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main(){
    List l1;
    l1.insertatfirst(50);
    l1.insertatfirst(40);
    l1.insertatfirst(30);
    l1.insertatfirst(20);
    l1.insertatfirst(10);

    printlist(l1.head);
    l1.head = zigzag(l1.head);
    printlist(l1.head);

    return 0;
}