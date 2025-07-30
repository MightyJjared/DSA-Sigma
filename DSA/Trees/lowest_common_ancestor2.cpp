#include <iostream>
#include <vector>
using  namespace std;

// This function finds the Lowest Common Ancestor (LCA) of two nodes (n1 and n2) in a binary tree.
// The approach is: Traverse the tree recursively. If current node matches n1 or n2, return it.
// Then check in left and right subtrees: 
// - If both return non-NULL, current node is the LCA.
// - If only one side is non-NULL, return that up.
// - If both are NULL, return NULL.
// Time Complexity: O(n) — where n is the number of nodes in the tree (each node visited once).
// Space Complexity: O(1).

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

static int idx = -1;
node* binarytree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    node* root = new node(preorder[idx]);

    root->left = binarytree(preorder);
    root -> right = binarytree(preorder);
    return root;
}

node* LCA2(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2){
        return root;
    }
    node* left = LCA2(root -> left,n1,n2);
    node* right = LCA2(root -> right,n1,n2);
    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL || right == NULL){
        if(left == right){
            return NULL;
        }
        if(left == NULL){
            return root -> right;
        }
        else{
            return root -> left;
        }
    }
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *  root = binarytree(preorder);
    cout << LCA2(root,4,5)->data << endl;
    return 0; 
}