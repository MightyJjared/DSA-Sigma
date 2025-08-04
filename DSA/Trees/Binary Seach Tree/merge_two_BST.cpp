#include <iostream>
#include <vector>
using namespace std;

/*
  approach_ two merge two BST we will get their sorted order by using inorder_vector funtion then we will have two 
  sorted vectors which we will merge using mergesort logic and het a sorted vector named merged then we will pass it
  balances_BST function to get a BST and we will print its inorder.

  Before:
      BST 1:        BST 2:

        2              9
       / \            / \
      1   4          3  12

  Inorder Traversal of both:
    BST1: [1, 2, 4]
    BST2: [3, 9, 12]

  Merged: [1, 2, 3, 4, 9, 12]

  After (Balanced BST from merged list):

           3
         /   \
        2     9
       / \   / 
      1   4 12
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

node* merge_BST(node* root1, node* root2){
    vector<int> node1;
    vector<int> node2;
    vector<int> merged;

    inorder_vector(root1, node1);
    inorder_vector(root2, node2);

    int i = 0 , j = 0;
    while(i < node1.size() && j < node2.size()){
        if(node1[i] < node2[j]){
            merged.push_back(node1[i]);
            i++;
        }
        else{
            merged.push_back(node2[j]);
            j++;
        }
    }
    while(i < node1.size()){
        merged.push_back(node1[i]);
        i++;
    }
    while(j < node2.size()){
        merged.push_back(node2[j]);
        j++;
    }

    return balanced_BST(merged,0,merged.size()-1);
}

int main(){
    node* root1 = new node(2);
    root1 -> left = new node(1);
    root1 -> right = new node(4);
    

    node* root2 = new node(9);
    root2 -> left = new node(3);
    root2 -> right  = new node(12);

    node* root = merge_BST(root1, root2);
    preorder(root);
    cout << endl;
    return 0;
}
