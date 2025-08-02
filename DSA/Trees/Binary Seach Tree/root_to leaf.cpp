#include<iostream>
#include <vector>
using namespace std;

/*
   ✅ Question:
   Given an array of integers, build a Binary Search Tree (BST) and print **all root-to-leaf paths**.

   ✅ Approach:
   - First, we construct the BST using the standard insertion rule.
   - Then, we perform a recursive traversal:
     → At each node, we add it to a path vector.
     → When we reach a leaf node (both left and right are NULL), we print the current path.
     → After exploring both children, we backtrack by removing the current node from the path.

   ✅ Input:
   arr[] = {8,5,3,1,4,6,10,11,14}

   ✅ BST Constructed:
             8
           /   \
         5     10
        / \       \
       3   6       11
      / \
     1   4
               \
               14

   ✅ Output (all root-to-leaf paths):
   Path:
   8 5 3 1
   Path:
   8 5 3 4
   Path:
   8 5 6
   Path:
   8 10 11 14
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

void print(vector<int> vec){
    cout << "Path: " << endl;
    for(int i =0; i< vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void path(node* root, vector<int> vec){
    if(root == NULL){
        return;
    }
    vec.push_back(root -> data);

    if(root -> left == NULL && root -> right == NULL){
        print(vec);
        vec.pop_back();
        return;
    }

    path(root -> left, vec);
    path(root -> right, vec);
    
    vec.pop_back();
}

int main(){
    int arr[] = {8,5,3,1,4,6,10,11,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    node * root = buildBST(arr,n);
    vector<int> vec;
    path(root, vec);
    cout << endl;
    return 0;
}
