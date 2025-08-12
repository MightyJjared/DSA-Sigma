#include <iostream>
#include <algorithm>
using namespace std;


// its approach is difficult see mams video to understand.
/*
Question:
----------
Given a binary tree, find the size (number of nodes) of the largest subtree 
that is also a Binary Search Tree (BST).

A BST is defined as a tree in which, for every node:
    - All nodes in its left subtree have values less than the node's value.
    - All nodes in its right subtree have values greater than the node's value.
    - Both left and right subtrees must themselves be BSTs.

We need to return the size of the largest such BST found anywhere in the tree.

Example Tree (built in main):
------------------------------
            50
           /  \
         30    60
        / \    / \
       5  20  45  70
                  / \
                65   80

Explanation:
------------
- The largest BST in this tree is the subtree rooted at 60:
        60
       /  \
     45    70
           / \
         65   80
  This subtree has size = 5.
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

class info{
    public:
    bool is_bst;
    int min;
    int max;
    int size;

    info(bool is_bst, int min, int max, int size){
        this-> is_bst = is_bst;   
        this-> min = min;
        this-> max = max;
        this-> size = size;
    }
};

static int max_size = 0;

info* largest_bst_size(node* root){
    // if(root == NULL){
    //     return new info(true, INT8_MAX, INT8_MIN, 0); // can also use this insted of below 2
    // }

    if(root == NULL){
        return NULL;
    }
    if(root ->left == NULL && root -> right == NULL){
        return new info(true, root->data, root-> data, 1);
    }

    info* left_info = largest_bst_size(root -> left);
    info* right_info = largest_bst_size(root -> right);

    int current_min = min(root -> data, min(left_info -> min, right_info -> min));
    int current_max = max(root -> data, max(left_info -> max, right_info -> max));
    int current_size = left_info -> size + right_info -> size + 1;

    if(left_info -> is_bst && right_info -> is_bst
       && root -> data > left_info-> max
       && root -> data < right_info -> min){
        max_size = max(max_size, current_size);
        return new info(true, current_min, current_max, current_size);
       }

    return new info(false, current_min, current_max, current_size);
}

int main(){
    node* root = new node(50);
    root -> left = new node(30);
    root -> left -> left = new node(5);
    root -> left -> right = new node(20);

    root -> right = new node(60);
    root -> right -> left = new node(45);
    root -> right -> right = new node(70);
    root -> right -> right -> left = new node(65);
    root -> right -> right -> right = new node(80);

    largest_bst_size(root);
    cout << "max size = " << max_size << endl;

    return 0;
}
// also insted of size if they would haev asked to return the root of largets bst
// we just need to add static node* root100 == NULL below line 68; and root100 = root below line 92