#include <iostream>
#include <vector>
using namespace std;

// LeetCode 114: Flatten Binary Tree to Linked List
// Time Complexity: O(n), each node is visited once during preorder traversal.
// Space Complexity: O(n), for the result vector, recursion stack, and new nodes.

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
    void preorder(TreeNode* root, vector<int> &result){
        if(root == NULL){
            return;
        }
        
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }

        vector<int> result;
        preorder(root, result);

        TreeNode* temp = root;

        int size = result.size();        
        
        for(int i = 1; i < size; i++){
            temp -> left = NULL;
            temp -> right = new TreeNode(result[i]);
            temp = temp -> right;
        }
    }
};

void printTree(TreeNode* root) {
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
    printTree(root);

    return 0;
}
