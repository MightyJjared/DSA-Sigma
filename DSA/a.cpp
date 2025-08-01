#include <iostream>
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
        node* root = new node(val);
        return root;
    }

    if(root ->data > val){
        root -> left = insert(root -> left, val);
    }
    if(root ->data < val){
        root -> right = insert(root -> right, val);
    }
    return root;
}

node* buildBST(int arr[], int n){
    node* root = NULL;
    for(int i =0; i<n;i++){
        root = insert(root,arr[i]);
    }
    return root;
}

bool search(node* root, int target){
    if(root == NULL){
        return false;
    }

    if(root -> data == target){
        return true;
    }
    else if(root -> data > target){
        return search(root -> left, target);
    }
    else{
        return search(root -> right, target);
    }
}

node* inordersuccessor(node* root){
    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

node* deletenode(node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root -> data > val){
        root -> left = deletenode(root -> left, val);
    }
    else if(root -> data < val){
        root -> right =  deletenode(root -> right, val);
    }
    else{
        // root -> data == val
        // 1 child case
        if(root -> left == NULL && root -> right == NULL){
            delete(root);
            return NULL;
        }

        //  1 child case
        if(root -> left == NULL || root -> right == NULL){
            if(root -> left == NULL){
                return root -> right;
            }
            else{
                return root -> left;
            }
        }

        // 2 child case
        node* Inorder = inordersuccessor(root -> right);
        root -> data = Inorder -> data;
        root -> right = deletenode(root -> right, Inorder -> data);
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
    cout << search(root, 4) <<endl;
    deletenode(root, 4);
    inorder(root);
    cout << endl;
    return 0;
}