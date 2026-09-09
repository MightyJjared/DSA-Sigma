/*
LeetCode Reference: 99 - Recover Binary Search Tree
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Recover BST using Morris Inorder Traversal
    void recoverTree(TreeNode* root) {

        // Current node for Morris traversal
        TreeNode* current = root;

        // Previous node in inorder traversal
        TreeNode* previous = NULL;

        // First and second incorrect nodes
        TreeNode* first = NULL;
        TreeNode* second = NULL;

        // Perform Morris Inorder Traversal
        while (current != NULL) {

            // Case 1: Current node has no left subtree
            if (current->left == NULL) {

                // Check for an inorder violation
                if (previous != NULL && previous->val > current->val) {

                    // Store first incorrect node
                    if (first == NULL) {
                        first = previous;
                    }

                    // Store second incorrect node
                    second = current;
                }

                // Current becomes previous
                previous = current;

                // Move to right subtree
                current = current->right;
            }

            // Case 2: Current node has a left subtree
            else {

                // Find inorder predecessor
                TreeNode* predecessor = current->left;

                while (predecessor->right != NULL &&
                       predecessor->right != current) {

                    predecessor = predecessor->right;
                }

                // Create temporary link
                if (predecessor->right == NULL) {

                    predecessor->right = current;

                    // Move to left subtree
                    current = current->left;
                }

                // Temporary link already exists
                else {

                    // Remove temporary link
                    predecessor->right = NULL;

                    // Check for an inorder violation
                    if (previous != NULL && previous->val > current->val) {

                        // Store first incorrect node
                        if (first == NULL) {
                            first = previous;
                        }

                        // Store second incorrect node
                        second = current;
                    }

                    // Current becomes previous
                    previous = current;

                    // Move to right subtree
                    current = current->right;
                }
            }
        }

        // Swap the values of the two incorrect nodes
        swap(first->val, second->val);
    }
};

// Print inorder traversal
void printInorder(TreeNode* root) {

    // Base case
    if (root == NULL) {
        return;
    }

    // Traverse left subtree
    printInorder(root->left);

    // Print current node
    cout << root->val << " ";

    // Traverse right subtree
    printInorder(root->right);
}

int main() {

    /*
            3
           / \
          1   4
             /
            2
    */

    // Create the BST with two swapped values
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    // Create Solution object
    Solution obj;

    // Recover the BST
    obj.recoverTree(root);

    // Print the corrected inorder traversal
    cout << "Inorder after recovery: ";

    printInorder(root);

    cout << endl;

    return 0;
}