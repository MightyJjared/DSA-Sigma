#include <iostream>
#include <vector>
#include <queue>
using  namespace std;
// time complexty = O(n) more optimised then previous one

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

pair<int, int> diameter(node* root){
    // in this pair first value is diameter and second is height
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int, int> left_pair = diameter(root -> left);
    pair<int, int> right_pair = diameter(root -> right);

    int current_diameter = left_pair.second + right_pair.second + 1;
    int max_diameter = max(current_diameter, max(left_pair.first, right_pair.first));
    int max_height = max(left_pair.second, right_pair.second) + 1;
    return make_pair(max_diameter, max_height);
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *  root = binarytree(preorder);
    cout << "diameter = " << diameter(root).first << endl;
    return 0; 
}