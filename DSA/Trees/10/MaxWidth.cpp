#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// This is hard see striver
// Time Complexity: O(N), where N is the number of nodes.


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){ 
            return 0; 
        } 
 
        queue<pair<TreeNode*, long long>> q; 
        q.push({root, 0}); 
 
        int result = 0; 
 
        while(q.size() != 0){ 
            int size = q.size(); 
 
            long long firstnode = 1e9; 
            long long lastnode = -1e9; 
             
            long long minColumn = q.front().second; 
 
            for(int i = 0; i < size; i++){ 
 
                TreeNode* node = q.front().first; 
                long long column = q.front().second; 
 
                q.pop(); 
                 
                column = column - minColumn; 
 
                // calculating result 
                firstnode = min(firstnode, column); 
                lastnode = max(lastnode, column); 
                int currentResult = lastnode - firstnode +1; 
                result = max(result, currentResult); 
 
                if(node->left != NULL){ 
                    long long nextColumn = 2*column + 1; 
                    q.push({node->left, nextColumn}); 
                } 
 
                if(node->right != NULL){ 
                    long long nextColumn = 2*column + 2; 
                    q.push({node->right, nextColumn}); 
                } 
            } 
        } 
        return result; 
    }
};

// Time Complexity: O(N), where N is the number of nodes.

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(9);

    Solution solution;

    cout << "Maximum width: " << solution.widthOfBinaryTree(root) << endl;

    return 0;
}