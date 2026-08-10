#include <iostream>
#include <vector>
#include <algorithm>
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

    node* root = new node(preorder[index]);

    root->left = binarytree(preorder);
    root->right = binarytree(preorder);

    return root;
}

int height(node* root, int &maxi){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left, maxi);
    left = max(0, left);

    int right = height(root->right, maxi);
    right = max(0, right);

    maxi = max(maxi, left + right + root->data);

    return max(left, right) + root->data;
}

int maxPathSum(node* root){

    if(root == NULL){
        return 0;
    }

    int maxi = -1e9;

    height(root, maxi);

    return maxi;
}

int main(){

    vector<int> preorder = {
        1, 2, -1, -1,
        3, 4, -1, -1,
        5, -1, -1
    };

    node* root = binarytree(preorder);

    cout << maxPathSum(root) << endl;

    return 0;
}