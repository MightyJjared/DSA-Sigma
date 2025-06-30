#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

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

static int index = -1;
node* binarytree(vector<int> preorder){
    index++;
    if(preorder[index] == -1){
        return NULL;
    }
    node* root = new node(preorder[index]);
    root -> left = binarytree(preorder);
    root -> right = binarytree(preorder);
    return root;
}

int sum(node* root){
    if(root == NULL){
        return 0;
    }
    int leftheight = sum(root -> left);
    int rightheight = sum(root -> right);
    int currentSum = (leftheight + rightheight) + root->data;
    return currentSum;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *  root = binarytree(preorder);
    cout << sum(root) << endl;
    return 0; 
}