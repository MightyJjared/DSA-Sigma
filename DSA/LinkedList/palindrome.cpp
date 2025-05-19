#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;

public:
    List() {
        head = NULL;
    }

    void insertAtLast(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    bool isPalindrome() {
        // Step 1: Traverse the list and add each element to an array
        vector<int> arr;
        Node* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Step 2: Use two pointers (start and end) to check elements
        int start = 0;
        int end = arr.size() - 1;
        while (start < end) {
            if (arr[start] != arr[end]) {
                // If elements don't match, it's not a palindrome
                return false;
            }
            start++;
            end--;
        }

        // If all elements matched, it's a palindrome
        return true;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List l1;
    l1.insertAtLast(1);
    l1.insertAtLast(2);
    l1.insertAtLast(2);
    l1.insertAtLast(1);
    l1.printList();

    // Check if list is palindrome
    cout << (l1.isPalindrome() ? "true" : "false") << endl;

    List l2;
    l2.insertAtLast(1);
    l2.insertAtLast(2);
    l2.printList();

    // Check if list is palindrome
    cout << (l2.isPalindrome() ? "true" : "false") << endl;

    return 0;
}
