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
    
    Node* merge(Node* head, Node* RightHead){
        List ans;
        Node* i = head;
        Node* j = RightHead;
    
        while(i != NULL && j != NULL){
            if(i -> data <= j -> data){
                ans.insertatlast(i -> data);
                i = i-> next;
            }
            else{
                ans.insertatlast(j -> data);
                j = j-> next;
            }
        }
        while (i != NULL){
            ans.insertatlast(i -> data);
                i = i-> next;
        }
        while(j != NULL){
            ans.insertatlast(j -> data);
                j = j-> next;
        }
        return ans.head;
    }
    
    Node* mergesort(Node* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        Node* RightHead = splitAtMid(head);
    
        Node* left = mergesort(head);
        Node* right = mergesort(RightHead);
    
        return merge(left, right);
    }
};

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
    l1.insertatfirst(10);
    l1.insertatfirst(20);
    l1.insertatfirst(30);
    l1.insertatfirst(40);

    printlist(l1.head);

    l1.head = l1.mergesort(l1.head);
    printlist(l1.head);

    return 0;
}