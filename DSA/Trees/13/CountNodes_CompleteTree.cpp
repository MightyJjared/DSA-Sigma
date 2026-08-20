#include <iostream>
#include <cmath>
using namespace std;

// leetcode 222
/*
    Time Complexity:

    A complete binary tree has height O(log N).

    leftHeight() takes O(log N)
    rightHeight() takes O(log N)

    At each level of recursion, we calculate these heights,
    which takes O(log N).

    The recursion can go through O(log N) levels.

    Therefore:

        O(log N) × O(log N)
        = O(log² N)

    Time Complexity = O(log² N)

    Space Complexity:

    The recursion depth is equal to the height of the tree.

    Height of a complete binary tree = O(log N)

    Space Complexity = O(log N)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    int rightHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return rightHeight(root->right) + 1;
    }

    int leftHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return leftHeight(root->left) + 1;
    }

    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftheight = leftHeight(root);
        int rightheight = rightHeight(root);

        if (leftheight == rightheight) {
            return pow(2, leftheight) - 1;
        }

        // Else case:
        // The subtree is not perfect, so recursively count
        // the nodes in the left and right subtrees.
        int lefthelper = helper(root->left);
        int righthelper = helper(root->right);

        return lefthelper + righthelper + 1;
    }

    int countNodes(TreeNode* root) {
        return helper(root);
    }
};



int main() {

    // Example tree:
    //
    //          1
    //        /   \
    //       2     3
    //      / \   /
    //     4   5 6

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    Solution obj;

    cout << "Number of nodes: " << obj.countNodes(root) << endl;

    return 0;
}