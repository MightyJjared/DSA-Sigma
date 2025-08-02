#include <iostream>
#include <vector>
using namespace std;

/*
    🟩 Question:
    Given an unbalanced Binary Search Tree (BST), balance it to minimize the height 
    while preserving the BST properties.

    🟦 Approach:
    1. Perform inorder traversal of the BST to get the sorted elements.
    2. Use the sorted array to build a balanced BST:
       - Pick the middle element as root.
       - Recursively build left subtree from the left half.
       - Recursively build right subtree from the right half.
    3. This ensures minimal height and balanced node distribution.

    🧠 Time Complexity: O(n)
    🧠 Space Complexity: O(n) (for storing inorder vector and recursion stack)

    🌲 Before (Unbalanced BST):
                 6
                / \
               5   7
              /     \
             4       8
            /         \
           3           9

    🌳 After (Balanced BST):
                 6
               /   \
              4     8
             / \   / \
            3   5 7   9
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

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

node* balanced_BST(vector<int> &arr, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);

    root->left = balanced_BST(arr, start, mid - 1);
    root->right = balanced_BST(arr, mid + 1, end);

    return root;
}

void inorder_vector(node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    inorder_vector(root -> left, arr);
    arr.push_back(root -> data);
    inorder_vector(root -> right, arr);
}

int main(){
    node* root = new node(6);
    root -> left = new node(5);
    root -> left -> left = new node(4);
    root -> left -> left -> left = new node(3);

    root -> right = new node(7);
    root -> right -> right = new node(8);
    root -> right -> right -> right = new node(9);

    vector<int> arr;
    inorder_vector(root,arr);

    root = balanced_BST(arr,0,arr.size()-1);
    preorder(root);
    return 0;
}