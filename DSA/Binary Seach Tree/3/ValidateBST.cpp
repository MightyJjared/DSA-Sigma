#include <iostream>
#include <climits>
using namespace std;

/*
LeetCode Reference: 98. Validate Binary Search Tree
Time Complexity: O(n), where n is the number of nodes
Space Complexity: O(h), where h is the height of the tree due to recursion
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

    // Checks whether every node lies within its allowed range
    bool helper(TreeNode* root, long long mini, long long maxi) {

        if (root == NULL) {
            return true;
        }

        // Current node must be strictly within the allowed range
        if (root->val >= maxi || root->val <= mini) {
            return false;
        }

        // Left subtree must contain values smaller than current node
        if (helper(root->left, mini, root->val) == false) {
            return false;
        }

        // Right subtree must contain values greater than current node
        if (helper(root->right, root->val, maxi) == false) {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {

        // Start with the complete long long range
        long long maxi = LLONG_MAX;
        long long mini = LLONG_MIN;

        return helper(root, mini, maxi);
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

    // Creating the BST
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    // Check whether the tree is a valid BST
    if (obj.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    }
    else {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}