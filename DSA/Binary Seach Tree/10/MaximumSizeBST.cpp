
// This is same as MaximumSumBST only 1 word differnece in 1 line

/*
LeetCode Reference: 333 - Largest BST Subtree
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
    int size;
    bool isBST;

    // Constructor
    Info(int mini, int maxi, int size, bool isBST) {
        this->mini = mini;
        this->maxi = maxi;
        this->size = size;
        this->isBST = isBST;
    }
};

// Find information about the subtree
Info helper(TreeNode* root, int& result) {

    // Empty tree is a BST of size 0
    if (root == NULL) {
        return Info(INT_MAX, INT_MIN, 0, true);
    }

    // Get information from left subtree
    Info left = helper(root->left, result);

    // Get information from right subtree
    Info right = helper(root->right, result);

    // Check whether current subtree is a BST
    if (left.isBST &&
        right.isBST &&
        root->val > left.maxi &&
        root->val < right.mini) {

        // Calculate size of current BST
        int currentSize = left.size + right.size + 1;

        // Update maximum BST size
        result = max(result, currentSize);

        // Return information about current BST
        return Info(
            min(left.mini, root->val),
            max(right.maxi, root->val),
            currentSize,
            true
        );
    }

    // Current subtree is not a BST
    return Info(INT_MIN, INT_MAX, 0, false);
}

int largestBSTSubtree(TreeNode* root) {

    // Store maximum BST size
    int result = 0;

    // Start recursion
    helper(root, result);

    return result;
}

int main() {

    /*
            50
           /  \
         30    60
        / \    / \
       5  20  45  70
                  / \
                 65 80
    */

    // Create tree
    TreeNode* root = new TreeNode(50);

    root->left = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);

    root->right = new TreeNode(60);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);

    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);

    // Find largest BST subtree
    cout << "Largest BST Size: "
         << largestBSTSubtree(root) << endl;

    return 0;
}