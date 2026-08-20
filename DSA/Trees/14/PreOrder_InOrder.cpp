#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode 105 it is a bit hard so see striver
/*
Time Complexity: O(n), each node is processed once.
Space Complexity: O(n), for the map and recursive call stack.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* helper(vector<int>& inorder, int InStart, int InEnd,
                     vector<int>& preorder, int PreStart, int PreEnd,
                     unordered_map<int, int>& index) {

        if (InStart > InEnd || PreStart > PreEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[PreStart]);

        int partition_index = index[preorder[PreStart]];
        int NumsLeft = partition_index - InStart;

        root->left = helper(
            inorder,
            InStart,
            partition_index - 1,
            preorder,
            PreStart + 1,
            NumsLeft + PreStart,
            index
        );

        root->right = helper(
            inorder,
            partition_index + 1,
            InEnd,
            preorder,
            NumsLeft + PreStart + 1,
            PreEnd,
            index
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> index;

        int size = preorder.size();

        for (int i = 0; i < size; i++) {
            int val = inorder[i];
            index[val] = i;
        }

        return helper(
            inorder,
            0,
            size - 1,
            preorder,
            0,
            size - 1,
            index
        );
    }
};

void printInorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);

    return 0;
}