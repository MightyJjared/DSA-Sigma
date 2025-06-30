#include <iostream>
#include <queue>
#include <vector>
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

static int index = -1;

node* binarytree(vector<int> preorder){
    index++;
    if(preorder[index] == -1){
        return NULL;
    }
    node* current_node  = new node(preorder[index]);
    current_node -> left = binarytree(preorder);
    current_node -> right = binarytree(preorder);

    return current_node;
}

void Preorder(node* root){
    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    Preorder(root -> left);
    Preorder(root -> right);
}


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *  root = binarytree(preorder);
    Preorder(root);
    cout  <<  endl;
    return 0; 
}