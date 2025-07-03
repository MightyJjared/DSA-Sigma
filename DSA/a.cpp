#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    node(int x){
        data = x;
        right = left = NULL;
    }
};

node* insert(node* root, int value){
    if(root == NULL){ // hi
        root = new node(value);
        return root;
    }
    if(value < root -> data){
        root -> left = insert(root -> left, value);
    }
    else if(value > root -> data){
        root -> right = insert(root -> right, value);
    }
    return root;
}

node* BST(vector<int> vec, int size){
    node* root = NULL;
    for(int i =0; i< size; i++){
        root = insert(root, vec[i]);
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

bool search(node * root, int target){
    if(root == NULL){
        return false;
    }
    if(root -> data == target){
        return true;
    }
    else if(root -> data < target){
        return search(root -> right, target);
    }
    else {
        return search(root -> left, target);
    }
}

int findmin(node* root){
    if(root == NULL){
        cout << "Tree is empty.\n";
        return -1;
    }
    while(root -> left != NULL){
        root = root -> left;
    }
    return root -> data;
}

int findmax(node* root){
    if(root == NULL){
        cout << "Tree is empty.\n";
        return -1;
    }
    while(root -> right != NULL){
        root = root -> right;
    }
    return root -> data;
}

int main(){
    vector<int> vec = {5,2,8,1,9,6,9,3};
    int size = vec.size();
    node* root = BST(vec, size);
    inorder(root);
    cout << endl;
    cout << search(root, 8) << endl;
    cout << "Min is : " << findmin(root) << endl;
    cout << "Max is : " << findmax(root) << endl;
    return 0;
}
