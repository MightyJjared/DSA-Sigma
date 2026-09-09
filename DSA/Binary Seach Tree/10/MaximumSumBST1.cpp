/*
LeetCode Reference: 1373 - Maximum Sum BST in Binary Tree
Time Complexity: O(n)
Space Complexity: O(h)
*/

#include <bits/stdc++.h>
using namespace std;

// Binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Stores information about a subtree
class Info {
public:
    int mini;
    int maxi;
    int sum;
    bool isBST;

    // Constructor
    Info(int mini, int maxi, int sum, bool isBST) {
        this->mini = mini;
        this->maxi = maxi;
        this->sum = sum;
        this->isBST = isBST;
    }
};

// Find information about the subtree
Info helper(TreeNode* root, int& result) {

    // Empty tree is a BST
    if(root == NULL) {
        return Info(INT_MAX, INT_MIN, 0, true);
    }

    // Get information from left subtree
    Info left = helper(root->left, result);

    // Get information from right subtree
    Info right = helper(root->right, result);

    // Check whether current subtree is a BST
    if(left.isBST &&
       right.isBST &&
       left.maxi < root->val &&
       root->val < right.mini) {

        // Calculate current subtree sum
        int currentSum = left.sum + right.sum + root->val;

        // Update maximum sum
        result = max(result, currentSum);

        // Return information about current subtree
        return Info(
            min(left.mini, root->val),
            max(right.maxi, root->val),
            currentSum,
            true
        );
    }

    // Current subtree is not a BST
    return Info(INT_MIN, INT_MAX, 0, false);
}

int maxSumBST(TreeNode* root) {

    // Store maximum BST sum
    int result = 0;

    // Start recursion
    helper(root, result);

    return result;
}

int main() {

    /*
            1
           / \
          4   3
         / \ / \
        2  4 2  5
    */

    // Create tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(4);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);

    // Find maximum sum BST
    cout << "Maximum Sum BST: " << maxSumBST(root) << endl;

    return 0;
}