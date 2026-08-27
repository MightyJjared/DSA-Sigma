#include <iostream>
using namespace std;

// Time Complexity: O(H), where H is the height of the BST.
// Space Complexity: O(1), since we use no recursion or extra data structures.

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

    int findCeil(Node* root, int x) {

        int ans = -1;

        while(root != NULL) {

            // If x exists, it is the ceiling
            if(root->data == x) {
                return x;
            }

            // Current value is smaller than x,
            // so the ceiling must be in the right subtree
            if(root->data < x) {
                root = root->right;
            }

            // Current value is greater than x,
            // so it is a possible ceiling
            else {
                ans = root->data;

                // Look for a smaller possible ceiling
                root = root->left;
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

    int x = 9;

    Solution obj;

    cout << "Ceiling of " << x << " is: "
         << obj.findCeil(root, x) << endl;

    return 0;
}