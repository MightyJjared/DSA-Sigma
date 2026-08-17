#include <iostream>
using namespace std;

// The question is from coding ninjas also from striver lecture 29 tree
// Time Complexity: O(N), where N is the number of nodes.
// Space Complexity: O(H), where H is the height of the tree due to recursion.


/*
Self Notes 📜:
🥥 if both children sum is less than parent, make children's value to parent's value.
🥥 if both children values sum is greater than or equal to parent, make parent's value to children's sum.
🥥 recursively go left and right. Traversal type: DFS.
🥥 when coming back up the tree, take children sum and replace it in parent.
🥥 at any point we reach null, just return (base case)
🥥 Intuition: while going down, increase the children values so we make sure to never fall short, 
then all we have to do is sum both children and replace it in parent.
*/

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int helper(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }

    if(root -> right != NULL && root->left != NULL){
        if(root->right->data + root->left->data < root->data){
            root->right->data = root->data;
            root->left->data = root->data;
        }
    }
    else if(root -> right != NULL){
        if(root->right->data < root->data){
            root->right->data = root->data;
        }
    }
    else if(root -> left != NULL){
        if(root->left->data < root->data){
            root->left->data = root->data;
        }
    }

    int leftHelper = helper(root->left);
    int rightHelper = helper(root->right);

    if(root->left != NULL || root->right != NULL) {
        root->data = leftHelper + rightHelper;
    }
    
    return root->data;
}

// Time Complexity: O(N), where N is the number of nodes.
// Space Complexity: O(H), where H is the height of the tree due to recursion.

void changeTree(BinaryTreeNode* root) {
    helper(root);
}

int main() {

    BinaryTreeNode* root = new BinaryTreeNode(10);

    root->left = new BinaryTreeNode(4);
    root->right = new BinaryTreeNode(6);

    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(2);

    changeTree(root);

    cout << root->data << endl;
    cout << root->left->data << " " << root->right->data << endl;
    cout << root->left->left->data << " "
         << root->left->right->data << endl;

    return 0;
}