#include <iostream>
#include <vector>
using namespace std;

/*
GFG Reference: Inorder Predecessor and Successor in BST
Time Complexity: O(n), where n is the number of nodes
Space Complexity: O(n), for the inorder vector
*/

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    // Stores the inorder traversal in sorted order
    void inorder(TreeNode* root, vector<int> &inorderValues) {

        if (root == NULL) {
            return;
        }

        // Traverse left subtree
        inorder(root->left, inorderValues);

        // Store current node
        inorderValues.push_back(root->data);

        // Traverse right subtree
        inorder(root->right, inorderValues);
    }

    vector<int> succPredBST(TreeNode* root, int key) {

        vector<int> inorderValues;

        // Generate inorder traversal
        inorder(root, inorderValues);

        int predecessor = -1;
        int successor = -1;

        // Find the position of the key
        for (int i = 0; i < inorderValues.size(); i++) {

            if (inorderValues[i] == key) {

                // Element before key is predecessor
                if (i > 0) {
                    predecessor = inorderValues[i - 1];
                }

                // Element after key is successor
                if (i < inorderValues.size() - 1) {
                    successor = inorderValues[i + 1];
                }

                break;
            }
        }

        // Return predecessor and successor
        return {predecessor, successor};
    }
};

int main() {

    /*
              20
             /  \
            8    22
           / \
          4   12
             /  \
            10  14
    */

    // Creating the BST
    TreeNode* root = new TreeNode(20);

    root->left = new TreeNode(8);
    root->right = new TreeNode(22);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);

    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    Solution obj;

    // Find predecessor and successor of 12
    int key = 12;

    vector<int> ans = obj.succPredBST(root, key);

    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;
}