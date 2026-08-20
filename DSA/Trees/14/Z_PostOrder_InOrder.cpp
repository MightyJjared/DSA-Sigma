#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode 106 it is a bit hard so see striver
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
                     vector<int>& postorder, int PostStart, int PostEnd,
                     unordered_map<int, int>& index) {

        if (InStart > InEnd || PostStart > PostEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[PostEnd]);

        int partition_index = index[postorder[PostEnd]];
        int numsleft = partition_index - InStart;

        root->left = helper(
            inorder,
            InStart,
            partition_index - 1,
            postorder,
            PostStart,
            numsleft + PostStart - 1,
            index
        );

        root->right = helper(
            inorder,
            partition_index + 1,
            InEnd,
            postorder,
            numsleft + PostStart,
            PostEnd - 1,
            index
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> index;

        int size = inorder.size();

        for (int i = 0; i < size; i++) {
            int val = inorder[i];
            index[val] = i;
        }

        return helper(
            inorder,
            0,
            size - 1,
            postorder,
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

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution obj;

    TreeNode* root = obj.buildTree(inorder, postorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);

    return 0;
}