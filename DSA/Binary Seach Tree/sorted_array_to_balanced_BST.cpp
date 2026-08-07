#include <iostream>
using  namespace std;

/*
    Question:
    Given a **sorted array**, convert it into a **Balanced Binary Search Tree (BST)**.

    Approach:
    - Use **Divide and Conquer** strategy:
      - Pick the middle element as the root.
      - Recursively build the left subtree using the left half of the array.
      - Recursively build the right subtree using the right half.
    - This ensures the tree is **balanced**, as we always divide the array evenly.

    Time Complexity: O(n), since we visit every element once.
    Space Complexity: O(log n) on average (due to recursion stack for balanced BST).

    Input: [1, 2, 3, 4, 5, 6, 7]

    Constructed Balanced BST:

               4
             /   \
           2       6
         /  \     /  \
        1    3   5    7

    Inorder traversal of this tree gives back the sorted array: 1 2 3 4 5 6 7
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

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* balanced_BST(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);

    root->left = balanced_BST(arr, start, mid - 1);
    root->right = balanced_BST(arr, mid + 1, end);

    return root;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    node* root = balanced_BST(arr, 0, n - 1);
    preorder(root);
    cout << endl;
    return 0;
}
