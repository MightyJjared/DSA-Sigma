#include <iostream>
using namespace std;

/*
    🧠 Q: Detect if a linked list contains a **cycle (loop)**.

    📌 Example:
        10 -> 20 -> 30 -> 40
                  ^        |
                  |________|

    🧪 Here, 40 points back to 20, creating a cycle.
    ✅ We need to detect whether such a cycle exists.

    🛠️ Approach: Floyd's Cycle Detection (Tortoise and Hare)
        - Use 2 pointers:
            • slow (moves 1 step at a time)
            • fast (moves 2 steps at a time)
        - If there is a cycle, fast and slow will eventually meet.
        - If no cycle, fast will reach NULL.

    ⏱️ Time Complexity: O(n)
    📦 Space Complexity: O(1)
*/

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

};

// Helper function to print the list (not used in case of cycle)
void printlist(Node* head){
    Node* temp = head; 
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

// Detect if there is a cycle in the linked list
bool isCycle(Node* head){ // Floyd's cycle algorithm 
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;           // moves 1 step
        fast = fast -> next -> next;   // moves 2 steps

        if(slow == fast){
            cout << "Cycle exist.\n";
            return true;
        }
    }
    cout << "Cycle doesn't exist.\n";
    return false;
}

// Main function
int main(){
    List l;
    l.insertatfirst(40);
    l.insertatfirst(30);
    l.insertatfirst(20);
    l.insertatfirst(10);

    // Making a cycle manually:
    // 40 -> next points back to 20
    l.tail->next = l.head->next; // Creates cycle

    isCycle(l.head);
    //printlist(l.head); // Don't use if a cycle exists
    return 0;
}
