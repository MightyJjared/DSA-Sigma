#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Question:
Given a preorder traversal with -1 as NULL, construct the binary tree and count total number of nodes.

Input:
vec = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}

Constructed Tree:
        1
       / \
      2   3
         / \
        4   5

Approach:
- Use recursive function `binarytree()` to build tree from preorder input.
- Use recursive `count()` to sum:
  count(left subtree) + count(right subtree) + 1 (for current node)

Time Complexity: O(n)
Space Complexity: O(h) — recursion stack
*/

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this -> data = data;
        left = right = NULL;
    }
};

static int idx = -1;
node* binarytree(vector<int> vec){
    idx++;
    if(vec[idx] == -1){
        return NULL;
    }
    node* root = new node(vec[idx]);
    root -> left = binarytree(vec);
    root -> right = binarytree(vec);
    return root;
}

int count(node* root){
    if(root == NULL){
        return 0;
    }
    int left_count = count(root->left);
    int right_count = count(root -> right);
    int current_count = left_count + right_count + 1;
    retur

