#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(h), where h is the height of the tree

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

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int leftheight = height(root -> left);
    int rightheight = height(root -> right);
    int currentHeight = max(leftheight, rightheight) + 1;
    return currentHeight;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }
    int current_diameter = height(root -> left) + height(root -> right);
    int left_diameter = diameter(root -> left);
    int right_diameter = diameter(root -> right);
    return max(current_diameter, max(left_diameter, right_diameter));
}


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *  root = binarytree(preorder);
    cout << "diameter = " << diameter(root) << endl;
    return 0; 
}