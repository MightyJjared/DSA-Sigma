#include <iostream>
using namespace std;

// Time Complexity: O(H), where H is the height of the BST.
// Space Complexity: O(1), since no extra data structures or recursion are used.

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:

    int findMaxFork(Node* root, int k) {

        int ans = -1;

        while(root != NULL) {

            // If k exists, it is the floor
            if(root->data == k) {
                return k;
            }

            // Current value is greater than k,
            // so the floor must be in the left subtree
            if(root->data > k) {
                root = root->left;
            }

            // Current value is smaller than k,
            // so it is a possible floor
            else {
                ans = root->data;

                // Look for a larger possible floor
                root = root->right;
            }
        }

        return ans;
    }
};

int main() {

    // Creating the BST:
    //
    //          8
    //         / \
    //        4   12
    //       / \  / \
    //      2  6 10 14
    //

    Node* root = new Node(8);

    root->left = new Node(4);
    root->right = new Node(12);

    root->left->left = new Node(2);
    root->left->right = new Node(6);

    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int k = 9;

    Solution obj;

    cout << "Floor of " << k << " is: "
         << obj.findMaxFork(root, k) << endl;

    return 0;
}