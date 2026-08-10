#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Time Complexity: O(n)

Why?
Every node is visited exactly once.
At each node:
    1. Calculate left height
    2. Calculate right height
    3. Update diameter
    4. Return height

We do not calculate the height of the same subtree repeatedly.

Space Complexity: O(h)

h = height of the tree.

Balanced tree:
O(log n)

Worst case (skewed tree):
O(n)
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

int height(node* root, int &diameter){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left, diameter);
    int right = height(root->right, diameter);

    diameter = max(diameter, left + right);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(node* root){

    if(root == NULL){
        return 0;
    }

    int max_diameter = -1e9;

    height(root, max_diameter);

    return max_diameter;
}


int main(){

    vector<int> preorder = {
        1, 2, -1, -1,
        3, 4, -1, -1,
        5, -1, -1
    };

    node* root = binarytree(preorder);

    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}