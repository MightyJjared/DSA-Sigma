#include <iostream>
#include <vector>
using namespace std;

// Here focus on 2 case
// 1 case - if root -> left == NULL then in inorder we can directly pushback the root and go to right
// case 2- if we get back to rooot from a threaded connection twice it means the first time we already
// made the thread connection so second time just print the currentnode and go to right

// LeetCode 94: Binary Tree Inorder Traversal
// Time Complexity: O(n), each node is visited a constant number of times.
// Space Complexity: O(1) (auxiliary space).
// but due to returning a vector space is o(n)

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    root = root-> left;
                }
                else if(temp -> right == root){
                    result.push_back(root->val);
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
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;

    vector<int> result = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    printVector(result);

    return 0;
}