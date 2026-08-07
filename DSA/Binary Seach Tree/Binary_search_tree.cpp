#include<iostream>
using namespace std;

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

void inorder(node * root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

bool search(node* root, int target){
    if(root == NULL){
        return false;
    }
    if(root -> data == target){
        return true;
    }
    else if(root -> data < target){
        return search(root -> right, target);
    }
    else{
        return search(root -> left, target);
    }
}

node* inorderSuccessor(node * root){
    // inorder successor is always the right childs left most node
    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
}

node* deletenode(node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(val < root -> data){
        root -> left = deletenode(root -> left, val);
    }
    else if(val > root -> data){
        root -> right = deletenode(root -> right, val);
    }
    else{
        // 0 child case
        if(root -> left == NULL && root -> right == NULL){
            delete(root);
            return NULL;
        }

        // 1 child case
        if(root -> left == NULL && root -> right != NULL){
            return root -> right;
        }
        else if(root -> right == NULL && root -> left != NULL){
            return root -> left;
        }

        // 2 child case
        // replace the root with its inorder successor
        // then delete the inorder successor
        node* inOrder = inorderSuccessor(root -> right);
        root -> data = inOrder -> data;
        root -> right = deletenode(root -> right, inOrder -> data);
        return root;
    }
    return root;
}

int main(){
    int arr[] = {5,1,3,4,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    node * root = buildBST(arr,n);
    inorder(root);
    cout << endl;
    deletenode(root, 5);
    inorder(root);
    cout << endl;
    return 0;
}