#include <iostream>
#include <list>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    stack<int> s;
    ListNode* temp = head;

    // Push all elements into the stack
    while(temp != NULL){
        s.push(temp->val);
        temp = temp->next;
    }

    // Compare again from the head
    temp = head;
    while(temp != NULL){
        if(temp->val != s.top()){
            return false;
        }
        s.pop();
        temp = temp->next;
    }

    return true;
}

int main() {
    list<int> input = {1, 2, 2, 1};  // Change to {1, 2} to test false case

    // Convert list<int> to linked list
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int val : input) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    // Cleanup memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
