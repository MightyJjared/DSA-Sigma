#include <iostream>
#include <vector>
using  namespace std;

/*
Question:
Given the preorder traversal of a binary tree (with -1 representing NULL), construct the tree and print the k-th ancestor of a given node.

Tree constructed from preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1}:
            1
          /   \
         2     3
        / \     \
       4   5     6

Example:
To find the 1st ancestor of node 5 (k=1), the output is 2.
Approach:
- Recursively traverse the tree to find the target node.
- As the recursive calls backtrack, count how far we are from the target.
- When the count equals k, print the current node’s value (which is the k-th ancestor).
- Time complexity = O(n), Space complexity = O(h) (due to recursion stack).
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

int static idx = -1;
node* binarytree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    node* root = new node(preorder[idx]);

    root -> left = binarytree(preorder);
    root -> right = binarytree(preorder);
    
    return root;
}

int kth_ancestor(node* root, int node, int k){
    if(root == NULL){
        return -1;
    }

    if(root -> data == node){
        return 1;
    }
    int left = kth_ancestor(root-> left, node,k);
    int right = kth_ancestor(root-> right, node,k);

    if(left == -1 || right == -1){
        if(left == right){
            return -1;
        }
        if(left == -1){
            if(right == k){
                cout<<  root -> data;
            }
            return right +1;
        }
        if(right == -1){
            if(left == k){
                cout<<  root -> data;
            }
            return left +1;
        }
    }
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *  root = binarytree(preorder);

    kth_ancestor(root,5,1);
    cout << endl;
    return 0;
}