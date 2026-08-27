#include <iostream>
using namespace std;

// Time Complexity: O(H), where H is the height of the BST.
// Space Complexity: O(1), since we use an iterative approach with no extra data structures.

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If the BST is empty, create the root node
        if(root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* curr = root;

        while(true) {

            // Insert in the left subtree
            if(curr->val > val) {

                if(curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }

            // Insert in the right subtree
            else {

                if(curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

int main() {

    // Creating the BST:
    //
    //          8
    //         / \
    //        4   12
    //       / \  / \
    //      2  6 10 14
    //

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(4);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int val = 5;

    Solution obj;

    root = obj.insertIntoBST(root, val);

    cout << "Inserted " << val << " into the BST." << endl;

    return 0;
}