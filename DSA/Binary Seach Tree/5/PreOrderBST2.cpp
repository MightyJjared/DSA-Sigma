#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
LeetCode Reference: 1008. Construct Binary Search Tree from Preorder Traversal
Time Complexity: O(n), where n is the number of nodes
Space Complexity: O(h), where h is the height of the BST due to recursion
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

    // Builds the BST using preorder and an upper bound
    TreeNode* helper(vector<int>& preorder, int& index, long long upperBound) {

        // Stop if all elements are processed or current value exceeds the bound
        if (index == preorder.size() || preorder[index] > upperBound) {
            return NULL;
        }

        // Current preorder element becomes the root
        TreeNode* root = new TreeNode(preorder[index]);

        // Move to the next preorder element
        index++;

        // Build left subtree, values must be smaller than root
        root->left = helper(preorder, index, root->val);

        // Build right subtree, values can go up to the current upper bound
        root->right = helper(preorder, index, upperBound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // Start from the first element with the largest possible bound
        int index = 0;

        return helper(preorder, index, LLONG_MAX);
    }
};

// Prints inorder traversal
void printInorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    printInorder(root->left);

    cout << root->val << " ";

    printInorder(root->right);
}

int main() {

    /*
        Preorder:
        8 5 1 7 10 12

        Constructed BST:

              8
             / \
            5   10
           / \    \
          1   7    12
    */

    // Given preorder traversal
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution obj;

    // Construct the BST
    TreeNode* root = obj.bstFromPreorder(preorder);

    // Verify using inorder traversal
    cout << "Inorder traversal: ";
    printInorder(root);

    cout << endl;

    return 0;
}