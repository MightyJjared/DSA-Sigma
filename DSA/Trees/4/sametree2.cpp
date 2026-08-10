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

bool helper(node* p, node* q){

    if(p == NULL || q == NULL){
        return p == q;
    }

    if(helper(p->left, q->left) == false){
        return false;
    }

    if(helper(p->right, q->right) == false){
        return false;
    }

    if(p->data != q->data){
        return false;
    }

    return true;
}

bool isSameTree(node* p, node* q){
    return helper(p, q);
}

int main(){

    vector<int> preorder1 = {
        1, 2, -1, -1,
        3, -1, -1
    };

    vector<int> preorder2 = {
        1, 2, -1, -1,
        3, -1, -1
    };

    node* root1 = binarytree(preorder1);

    index = -1;

    node* root2 = binarytree(preorder2);

    if(isSameTree(root1, root2)){
        cout << "Both trees are same" << endl;
    }
    else{
        cout << "Trees are different" << endl;
    }

    return 0;
}