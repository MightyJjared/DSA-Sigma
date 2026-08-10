#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/*
Time Complexity: O(n^2) in the worst case

Why?
helper() visits every node once.
But at every node, height() traverses the subtree again.
Therefore, heights are calculated repeatedly.

Space Complexity: O(h)

h = height of the tree.
This space is used by the recursion stack.

Worst case (skewed tree): O(n)
Balanced tree: O(log n)
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

int height(node* root){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

bool helper(node* root){

    if(root == NULL){
        return true;
    }

    if(helper(root->left) == false){
        return false;
    }

    if(helper(root->right) == false){
        return false;
    }

    int left = height(root->left);
    int right = height(root->right);

    int result = abs(left - right);

    if(result > 1){
        return false;
    }

    return true;
}

bool isBalanced(node* root){
    return helper(root);
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