#include <iostream>
#include <vector>
using namespace std;

// To understand this just understand morris inorder traversal
// here there is only 1 line replacement from morris inrder traversal
// LeetCode 144: Binary Tree Preorder Traversal
// Time Complexity: O(n), each node is visited a constant number of times.
// Space Complexity:  auxiliary space is O(1).
// Space Complexity: O(n), for the result vector; 

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root == NULL){
            return result;
        }

        while(root != NULL){
            if(root -> left == NULL){
                result.push_back(root->val);
                root = root-> right;
            }
            else{
                TreeNode* temp = root->left;

                while(temp -> right != NULL && temp -> right != root){
                    temp = temp -> right;
                }

                if(temp -> right == NULL){
                    temp -> right = root;
                    result.push_back(root->val);
                    root = root-> left;
                }
                else if(temp -> right == root){
                    temp -> right = NULL;
                    root = root->right;
                }
            }
        }

        return result;
    }
};

void printVector(vector<int> result) {
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    vector<int> result = obj.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    printVector(result);

    return 0;
}