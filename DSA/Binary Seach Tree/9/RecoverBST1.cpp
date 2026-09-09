/*
LeetCode Reference: 99 - Recover Binary Search Tree
Time Complexity: O(n)
Space Complexity: O(h)
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

    // Inorder traversal to find the two incorrect nodes
    void inorder(TreeNode* root,
                 TreeNode*& temp1,
                 TreeNode*& temp2,
                 TreeNode*& previous) {

        // Base case
        if (root == NULL) {
            return;
        }

        // Traverse left subtree
        inorder(root->left, temp1, temp2, previous);

        // Check for an inorder violation
        if (previous != NULL && previous->val >= root->val) {

            // Store the first incorrect node
            if (temp1 == NULL) {
                temp1 = previous;
                temp2 = root;
            }
            else {
                // Update the second incorrect node
                temp2 = root;
            }

            // Update previous node
            previous = root;
        }
        else {
            // Update previous node normally
            previous = root;
        }

        // Traverse right subtree
        inorder(root->right, temp1, temp2, previous);
    }

    // Recover the BST
    void recoverTree(TreeNode* root) {

        // Initialize pointers
        TreeNode* temp = root;
        TreeNode* temp1 = NULL;
        TreeNode* temp2 = NULL;
        TreeNode* previous = NULL;

        // Find the two incorrect nodes
        inorder(temp, temp1, temp2, previous);

        // Store their values
        int val1 = temp1->val;
        int val2 = temp2->val;

        // Swap the values
        temp1->val = val2;
        temp2->val = val1;
    }
};

// Print inorder traversal
void printInorder(TreeNode* root) {

    // Base case
    if (root == NULL) {
        return;
    }

    // Print left subtree
    printInorder(root->left);

    // Print current node
    cout << root->val << " ";

    // Print right subtree
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