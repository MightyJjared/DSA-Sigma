#include <iostream>
#include <vector>
using namespace std;

// LeetCode 114: Flatten Binary Tree to Linked List
// Time Complexity: O(n), each node is processed a constant number of times.
// Space Complexity: O(1), no extra data structures are used.

/**
 * Definition for a binary tree node.
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
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        TreeNode* iterator = root;

        while(iterator != NULL){
            if(iterator->left != NULL){

                TreeNode* temp = iterator->left;

                while(temp->right != NULL){
                    temp = temp -> right;
                }

                temp -> right = iterator -> right;

                iterator -> right = iterator -> left;
                iterator -> left = NULL;
            }

            iterator = iterator -> right;
        }
    }
};

void printFlattenedTree(TreeNode* root) {
    while(root != NULL){
        cout << root->val << " ";
        root = root->right;
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution obj;

    obj.flatten(root);

    cout << "Flattened tree: ";
    printFlattenedTree(root);

    return 0;
}