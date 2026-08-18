#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Time Complexity: O(N) average, where N is the number of nodes.
// Space Complexity: O(N), where N is the number of nodes.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* currentnode, int k, vector<int> &result, unordered_map<TreeNode* , TreeNode*> &parent, unordered_map<TreeNode*, bool> &visited){ 
        if(currentnode == NULL){ 
            return; 
        } 
 
        if(visited[currentnode] == true){ 
            return; 
        } 
 
         if(k == 0){ 
            result.push_back(currentnode -> val); 
            return; //because then we will go k=1 and so on if we dont return; 
        } 
 
        visited[currentnode] = true; 
         
        k = k-1; 
        //down
         
        helper(currentnode->left, k, result, parent, visited); 
         
        helper(currentnode->right, k, result, parent, visited); 
         
 
        // up 
        helper(parent[currentnode], k, result, parent, visited); 
         
    } 
 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) { 
        unordered_map<TreeNode* , TreeNode*> parent; 
        vector<int> result; 
        queue<TreeNode*> q; 
 
        if(root == NULL){ // edge case 1 
            return result; 
        } 
 
        q.push(root); 
         
        // doing level order traversal and storing the parent of each root in a map 
        while(q.size() != 0){ 
            TreeNode* node = q.front(); 
            q.pop(); 
 
            if(node->left != NULL){ 
                q.push(node->left); 
                parent[node->left] = node; 
            } 
 
            if(node->right != NULL){ 
                q.push(node->right); 
                parent[node->right] = node; 
            } 
        } 
 
        unordered_map<TreeNode*, bool> visited; 
        helper(target, k, result, parent, visited); 
        return result; 
    } 
};

int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left;
    int k = 2;

    Solution solution;

    vector<int> result = solution.distanceK(root, target, k);

    for(int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}