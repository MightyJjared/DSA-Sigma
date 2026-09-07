#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
LeetCode Reference: 1008. Construct Binary Search Tree from Preorder Traversal
Time Complexity: O(n log n), due to sorting the inorder vector
Space Complexity: O(n), for the inorder vector, hashmap, and recursion stack
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

    // Builds the BST using preorder and inorder traversal
    TreeNode* helper(vector<int> &inorder, int inStart, int inEnd,
                     vector<int> &preorder, int preStart, int preEnd,
                     unordered_map<int, int> &m) {

        if (inStart > inEnd || preStart > preEnd) {
            return NULL;
        }

        // First element of preorder is the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root position in inorder
        int partitionIndex = m[preorder[preStart]];

        // Number of nodes present in the left subtree
        int numsleft = partitionIndex - inStart;

        // Build the left subtree
        root->left = helper(
            inorder,
            inStart,
            partitionIndex - 1,
            preorder,
            preStart + 1,
            preStart + numsleft,
            m
        );

        // Build the right subtree
        root->right = helper(
            inorder,
            partitionIndex + 1,
            inEnd,
            preorder,
            preStart + numsleft + 1,
            preEnd,
            m
        );

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // Inorder of a BST is the sorted preorder values
        vector<int> inorder = preorder;

        sort(inorder.begin(), inorder.end());

        // Store each value and its index in inorder
        unordered_map<int, int> m;

        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            int data = inorder[i];
            m[data] = i;
        }

        // Construct the BST
        return helper(inorder, 0, n - 1,
                      preorder, 0, n - 1, m);
    }
};

// Prints the inorder traversal of the tree
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

    // Display inorder traversal to verify the BST
    cout << "Inorder traversal: ";
    printInorder(root);

    cout << endl;

    return 0;
}