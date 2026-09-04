#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode Reference: 230. Kth Smallest Element in a BST
Time Complexity: O(n), where n is the number of nodes in the BST
Space Complexity: O(n) for the result vector and O(h) recursion stack
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

    // Performs inorder traversal and stores nodes in sorted order
    void inorder(TreeNode* root, vector<int> &result) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, result);

        // Store the current node
        result.push_back(root->val);

        inorder(root->right, result);
    }

    int kthSmallest(TreeNode* root, int k) {

        // Store the inorder traversal
        vector<int> result;

        inorder(root, result);

        // kth smallest element is at index k-1
        return result[k - 1];
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

    // Find the 3rd smallest element
    int k = 3;

    cout << "The " << k << "rd smallest element is: "
         << obj.kthSmallest(root, k) << endl;

    return 0;
}