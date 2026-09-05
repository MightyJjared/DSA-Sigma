#include <iostream>
using namespace std;

/*
LeetCode Reference: 230. Kth Smallest Element in a BST
Time Complexity: O(h + k), where h is the height of the BST
Space Complexity: O(h) due to the recursion stack
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

    // Performs inorder traversal to find the kth smallest element
    void inorder(TreeNode* root, int &k, int &answer) {

        if (root == NULL) {
            return;
        }

        // Traverse the left subtree first
        inorder(root->left, k, answer);

        // Stop if kth element has already been found
        if (k == 0) {
            return;
        }

        // Decrease k when visiting the current node
        k--;

        // Current node is the kth smallest element
        if (k == 0) {
            answer = root->val;
            return;
        }

        // Traverse the right subtree
        inorder(root->right, k, answer);
    }

    int kthSmallest(TreeNode* root, int k) {

        // Variable to store the answer
        int answer;

        inorder(root, k, answer);

        return answer;
    }
};

int main() {

    /*
             5
            / \
           3   7
          / \ / \
         2  4 6  8
    */

    // Creating the BST
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    // Find the 3rd smallest element
    int k = 3;

    cout << "The " << k << "rd smallest element is: "
         << obj.kthSmallest(root, k) << endl;

    return 0;
}