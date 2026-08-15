#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void helper(TreeNode* root, vector<vector<int>> &result, vector<int> &current){ 
    if(root == NULL){ 
        return; 
    } 
 
    current.push_back(root -> data); 
 
    if(root->left == NULL && root->right == NULL){ 
        result.push_back(current); 
    } 
 
    helper(root->left, result, current); 
    helper(root->right, result, current); 
 
    current.pop_back(); 
}

// Time Complexity: O(N * H) in the worst case, where N = number of nodes and H = height of tree.
// Space Complexity: O(H) recursion/path space, excluding the result.

int main() {

    // Creating the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> result;
    vector<int> current;

    helper(root, result, current);

    // Print all root-to-leaf paths
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}