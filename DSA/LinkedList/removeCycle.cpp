#include<iostream>
using namespace std;

/*
🧠 Q: Detect and remove a cycle (loop) in a linked list.

📌 Example (Before removal):

     +------+     +------+     +------+     +------+
     | 10  | •--->| 20  | •--->| 30  | •--->| 40  | •
     +------+     +------+     +------+     +------+
                        ^                          |
                        |                          |
                        +--------------------------+

Each circle has:
- Left half = data
- Right half (•) = pointer (next node)

🔄 Here, 40 → next points back to 20, forming a cycle.
🎯 Our goal is to remove the cycle so the list becomes:
[10|•] → [20|•] → [30|•] → [40|NULL]

🛠️ Approach:
1. Use Floyd’s algorithm to detect if a cycle exists.
2. If found, reset slow to head and move both slow and fast one step at a time.
3. When they meet again, the node just before meeting point (tracked by `prev`) is the last node of the cycle — break it.

📦 Space: O(1)
⏱️ Time: O(n)
*/

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// Linked list class
class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void insertatfirst(int val) {
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
};

// Print linked list (won't use it on cyclic list)
void printlist(Node* head){
    Node* temp = head; 
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to remove cycle if it exists
void removecycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    // Detect cycle using Floyd's algorithm
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout << "Cycle exists\n";
            isCycle = true;
            break;
        }
    }

    if(!isCycle){
        cout << "Cycle doesn't exist\n";
        return;
    }

    // Case 1: Cycle starts at head
    slow = head;
    if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    // Case 2: Cycle starts after head
    else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // Remove cycle
    }
}

// Main function
int main(){
    List l;
    l.insertatfirst(40);
    l.insertatfirst(30);
    l.insertatfirst(20);
    l.insertatfirst(10);

    // Make a cycle: tail (40) → next = node with 20
    l.tail->next = l.head->next; // [40]->next = 20

    removecycle(l.head);  // Detect and remove cycle
    printlist(l.head);    // Now safe to print

    return 0;
}
