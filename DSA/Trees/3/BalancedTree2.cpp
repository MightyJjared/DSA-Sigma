#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Time Complexity: O(n)

Why?
Every node is visited only once.
For every node:
    1. Calculate left height
    2. Calculate right height
    3. Check the height difference

We do NOT calculate the height of the same subtree repeatedly.

Space Complexity: O(h)

h = height of the tree.

Balanced tree:
O(log n)

Worst case (skewed tree):
O(n)
*/

class node{
public:
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

static int index = -1;

node* binarytree(vector<int> preorder){
    index++;

    if(preorder[index] == -1){
        return NULL;
    }

    node* root = new node(preorder[index]);

    root->left = binarytree(preorder);
    root->right = binarytree(preorder);

    return root;
}

int helper(node* root){

    if(root == NULL){
        return 0;
    }

    int left = helper(root->left);

    // -1 means the left subtree is not balanced
    if(left == -1){
        return -1;
    }

    int right = helper(root->right);

    // -1 means the right subtree is not balanced
    if(right == -1){
        return -1;
    }

    // If the difference between left and right heights is more than 1,
    // the current subtree is not balanced
    if(abs(left - right) > 1){
        return -1;
    }

    // Return the height of the current subtree
    return max(left, right) + 1;
}

bool isBalanced(node* root){

    if(helper(root) == -1){
        return false;
    }

    return true;
}


int main(){

    vector<int> preorder = {
        1, 2, -1, -1,
        3, 4, -1, -1,
        5, -1, -1
    };

    node* root = binarytree(preorder);

    if(isBalanced(root)){
        cout << "Tree is balanced" << endl;
    }
    else{
        cout << "Tree is not balanced" << endl;
    }

    return 0;
}