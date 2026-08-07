#include<iostream>
using namespace std;

/*
   ✅ Question:
   Given an array of integers, construct a Binary Search Tree (BST) and print all node values
   that lie within a given range [start, end].

   ✅ Approach:
   - First, insert each element of the array into the BST using standard BST insertion rules.
   - Then, perform a modified in-order traversal:
     → If the current node lies in the range, print it and check both left and right subtrees.
     → If it's less than start, explore only the right subtree.
     → If it's greater than end, explore only the left subtree.

   ✅ Example Input:
   arr[] = {8,5,3,1,4,6,10,11,14}
   range = [5, 12]

   ✅ BST Formed:
             8
           /   \
         5     10
        / \       \
       3   6       11
      / \            \
     1   4            14
     
               

   ✅ Output:
   5 6 8 10 11
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

node* insert(node* root, int val){
    if(root == NULL){
        root = new node(val);
        return root;
    }

    if(val < root -> data){
        root -> left = insert(root -> left, val);
    }
    else{
        root -> right = insert(root -> right, val);
    }
    return root;
}

node* buildBST(int arr[], int n){
    node* root = NULL;
    for(int i =0; i< n;i++){
       root =  insert(root, arr[i]);
    }
    return root;
}

void range(node* root, int start, int end){
    if(root == NULL){
        return;
    }

    if(start <= root -> data && root -> data <= end){
        cout << root -> data << " ";
        range(root -> left, start, end);
        range(root -> right, start, end);
    }
    else if(root -> data < start){
        range(root -> right, start, end);
    }
    else if(root -> data > end){
        range(root -> left, start, end);
    }
}

int main(){
    int arr[] = {8,5,3,1,4,6,10,11,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    node * root = buildBST(arr,n);
    range(root, 5, 12);
    cout << endl;
    return 0;
}
