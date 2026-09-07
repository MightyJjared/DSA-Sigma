#include <iostream>
#include <vector>
using namespace std;

/*
GFG Reference: Inorder Predecessor and Successor in BST
Time Complexity: O(h), where h is the height of the BST
Space Complexity: O(1), excluding the answer vector
*/

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    // Finds the inorder predecessor
    void Predecessor(TreeNode* root, int key, int &predecessor) {

        while (root != NULL) {

            // Current node is too large, move left
            if (root->data >= key) {
                root = root->left;
            }

            else {
                // Current node is a possible predecessor
                predecessor = root->data;

                // Try to find a larger predecessor
                root = root->right;
            }
        }
    }

    // Finds the inorder successor
    void Successor(TreeNode* root, int key, int &successor) {

        while (root != NULL) {

            // Current node is too small, move right
            if (root->data <= key) {
                root = root->right;
            }

            else {
                // Current node is a possible successor
                successor = root->data;

                // Try to find a smaller successor
                root = root->left;
            }
        }
    }

    vector<int> succPredBST(TreeNode* root, int key) {

        vector<int> ans;

        // -1 means predecessor/successor does not exist
        int predecessor = -1;
        int successor = -1;

        // Find predecessor
        Predecessor(root, key, predecessor);

        // Find successor
        Successor(root, key, successor);

        // Required order: predecessor, successor
        ans.push_back(predecessor);
        ans.push_back(successor);

        return ans;
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