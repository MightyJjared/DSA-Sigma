#include<iostream>
#include <vector>
using namespace std;


/*
    Question:
    Build a Binary Search Tree (BST) from a given array and validate whether the resulting tree 
    is a valid BST or not.

    Approach:
    1. We first construct the BST using the standard BST insert rules:
       - If value < current node, go to left subtree.
       - If value > current node, go to right subtree.
    2. To validate the BST:
       - We use a helper function that recursively checks if every node's value lies in a valid range.
       - For a node:
            - its value must be > all values in the left subtree (i.e., greater than `min`)
            - its value must be < all values in the right subtree (i.e., less than `max`)
       - We pass down updated `min` and `max` nodes as we recurse.

    Input Array: [8, 5, 3, 1, 4, 6, 10, 11, 14]

    BST Constructed (with min/max range for each node):

                8 (min=-∞, max=∞)
              /                 \
       5 (min=-∞, max=8)     10 (min=8, max=∞)
         /     \                  \
3 (min=-∞, max=5) 6 (min=5, max=8) 11 (min=10, max=∞)
       /  \                          \
1(-∞,3) 4(3,5)                    14(11,∞)

    Time Complexity:
    - Building BST: O(n log n) average, O(n^2) worst
    - Validation: O(n)

    Space Complexity:
    - O(h), where h is the height of the tree (stack space due to recursion)
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

bool helper(node* root, node* min, node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root -> data < min -> data){
        return false;
    }
    if(max != NULL && root -> data > max -> data){
        return false;
    }

    bool left = helper(root -> left, min, root); // here min stays same and max changes
    bool right = helper(root -> right, root, max); // here max stays same and min changes

    return left && right;
}

bool validate_BST(node* root){
    return helper(root, NULL, NULL);
}
int main(){
    int arr[] = {8,5,3,1,4,6,10,11,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    node * root = buildBST(arr,n);
    cout << validate_BST(root);
    cout << endl;
    return 0;
} 


