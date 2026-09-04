#include <iostream>
using namespace std;

// LeetCode 235: Lowest Common Ancestor of a Binary Search Tree
// Time Complexity: O(H), Space Complexity: O(H), where H is the height of the BST.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) {
            return NULL;
        }

        /*
        There are only 3 possibilities:

        1. Both p and q are smaller than root -> Go left.
        2. Both p and q are greater than root -> Go right.
        3. p and q are on opposite sides of root,
           or one of them is root -> Current root is the LCA.
        */

        // Both p and q are in the left subtree
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Both p and q are in the right subtree
        if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Case 3: Current root is the LCA
        return root;
    }
};

int main() {

    // BST:
    //
    //        6
    //       / \
    //      2   8
    //     / \
    //    0   4
    //       / \
    //      3   5

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;          // Node 2
    TreeNode* q = root->left->right;   // Node 4

    Solution obj;

    TreeNode* answer = obj.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: " << answer->val << endl;

    return 0;
}