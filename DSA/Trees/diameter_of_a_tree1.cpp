#include <iostream>
#include <vector>
#include <queue>
using  namespace std;
// time complexty = O(n^2)

    /*
        This vector represents the following binary tree:

                 1
               /   \
              2     3
                   / \
                  4   5

        - Each number represents a node.
        - -1 means NULL (no child in that direction).

        🌟 Diameter of the tree is defined as the length (in number of nodes)
        of the longest path between any two nodes in the tree.

        🔁 In this case, the longest path is:
            2 → 1 → 3 → 5
            Total nodes on this path = 4

        ✅ So, the output will be:
            diameter = 4
    */

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
    int current_diameter = height(root -> left) + height(root -> right) + 1;
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