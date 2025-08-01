#include <iostream>
using namespace std;

/*
Question:
Check if a binary tree is a unival tree — meaning all nodes in the tree contain the same value.

Tree Example (built in main):
        1
       / \
      1   1
     / \
    1   1

Since all nodes are 1, the output should be: true

Approach:
- Store the root's value.
- Recursively check every node.
- If any node doesn't match the root's value, return false.
- Otherwise, check left and right subtrees and return (left && right).

Time Complexity: O(n) — visits every node once.
Space Complexity: O(h) — due to recursion stack (h = height of tree).
*/

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

bool same(TreeNode* root, int k) {
    if (root == NULL) {
        return true;
    }

    if (root->val != k) {
        return false;
    }

    bool left = same(root->left, k);
    bool right = same(root->right, k);
    return left && right;
}

bool isUnivalTree(TreeNode* root) {
    if (root == NULL) return true; // edge case
    int k = root->val;
    return same(root, k);
}

int main() {
    // Build the tree:
    //         1
    //        / \
    //       1   1
    //      / \
    //     1   1

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);

    cout << boolalpha << isUnivalTree(root) << endl;  // Output: true

    return 0;
}

