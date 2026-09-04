#include <iostream>
using namespace std;

/*
LeetCode Reference: 450. Delete Node in a BST
Time Complexity: O(h), where h is the height of the BST
Space Complexity: O(h) due to recursive helper2 calls
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

class Solution {
public:

    // Finds the rightmost node of a subtree
    TreeNode* helper2(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }

        return helper2(root->right);
    }

    // Handles deletion when the current node contains the key
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        else if (root->right == NULL) {
            return root->left;
        }

        // Store the right subtree
        TreeNode* RightChild = root->right;

        // Find the rightmost node in the left subtree
        TreeNode* LeftestRight = helper2(root->left);

        // Attach the right subtree to it
        LeftestRight->right = RightChild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return NULL;
        }

        // If root itself contains the key
        if (root->val == key) {
            return helper(root);
        }

        // Keep the original root to return at the end
        TreeNode* dummy = root;

        while (root != NULL) {

            if (root->val > key) {

                // Key is present in the left subtree
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                }
                else {
                    root = root->left;
                }
            }

            if (root->val < key) {

                // Key is present in the right subtree
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};

int main() {

    /*
             5
            / \
           3   7
          / \ / \
         2  4 6  8
    */

    // Creating the tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    // Delete node with value 3
    root = obj.deleteNode(root, 3);

    cout << "Node deleted successfully." << endl;

    return 0;
}