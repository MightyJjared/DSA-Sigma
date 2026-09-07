#include <iostream>
#include <stack>
using namespace std;

/*
LeetCode Reference: 173. Binary Search Tree Iterator
Time Complexity: O(1) average time for next(), O(h) for initialization
Space Complexity: O(h), where h is the height of the BST
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class BSTIterator {
public:

    // Stack stores nodes whose values are yet to be returned
    stack<TreeNode*> s;

    // Pushes the complete left path into the stack
    void pushleft(TreeNode* root) {

        while (root != NULL) {
            s.push(root);

            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {

        // Initially push the leftmost path
        pushleft(root);
    }

    int next() {

        // Top of stack is the next smallest element
        TreeNode* current = s.top();

        s.pop();

        // Process the right subtree
        if (current->right != NULL) {
            pushleft(current->right);
        }

        return current->val;
    }

    bool hasNext() {

        // If stack is not empty, elements are remaining
        return !s.empty();
    }
};

int main() {

    /*
             7
            / \
           3   15
              /  \
             9   20
    */

    // Creating the BST
    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);

    // Print elements in sorted order
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }

    cout << endl;

    return 0;
}