#include <iostream>
#include <algorithm>
using namespace std;

// Time Complexity: O(H), where H is the height of the BST.
// Space Complexity: O(H) due to the recursion stack.

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

    void helper(Node* root, int x, int& ans) {

        if(root == NULL) {
            return;
        }

        // If x exists, it is the ceiling
        if(root->data == x) {
            ans = x;
            return;
        }

        // Current value is smaller than x,
        // so ceiling can only be in the right subtree
        if(root->data < x) {
            helper(root->right, x, ans);
        }

        // Current value is greater than x,
        // so it can be a possible ceiling
        else {
            ans = min(ans, root->data);

            // Look for a smaller possible ceiling
            helper(root->left, x, ans);
        }
    }

    int findCeil(Node* root, int x) {

        int ans = 1e9;

        helper(root, x, ans);

        if(ans == 1e9) {
            return -1;
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