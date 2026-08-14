#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity: O(n), because every node is visited once.
Space Complexity: O(h), where h is the height of the tree due to recursion.
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

static int index = -1;

node* binarytree(vector<int> preorder){
    index++;

    if(preorder[index] == -1){
        return NULL;
    }

    node* root = new node(preorder[index]);

    root->left = binarytree(preorder);
    root->right = binarytree(preorder);

    return root;
}

bool helper(node* l, node* r){

    if(l == NULL || r == NULL){
        if(l == r){
            return true;
        }
        else{
            return false;
        }
    }

    if(l->data != r->data){
        return false;
    }

    if(helper(l->left, r->right) == false ||
       helper(l->right, r->left) == false){
        return false;
    }

    return true;
}

bool isSymmetric(node* root){

    if(root == NULL){
        return true;
    }

    node* l = root->left;
    node* r = root->right;

    if(helper(l, r) == false){
        return false;
    }

    return true;
}

/*
Time Complexity: O(n), because every node is visited once.
Space Complexity: O(h), where h is the height of the tree due to recursion.
*/

int main(){

    vector<int> preorder = {
        1,
        2, 3, -1, -1, 4, -1, -1,
        2, 4, -1, -1, 3, -1, -1
    };

    node* root = binarytree(preorder);

    if(isSymmetric(root)){
        cout << "Tree is symmetric" << endl;
    }
    else{
        cout << "Tree is not symmetric" << endl;
    }

    return 0;
}