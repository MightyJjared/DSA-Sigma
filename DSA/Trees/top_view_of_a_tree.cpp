#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

    /*
    Question Explanation:

    Given a preorder traversal of a binary tree where -1 represents NULL,
    construct the binary tree and print its top view.

    Input:
    preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}

    Constructed Binary Tree:
            1
           / \
          2   3
         / \    \
        4   5    6

    Top View (nodes visible from top):
    Output: 4 2 1 3 6
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

static int idx = -1;
node* binarytree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    node* root = new node(preorder[idx]);

    root->left = binarytree(preorder);
    root -> right = binarytree(preorder);
    return root;
}

void topview(node* root){
    queue<pair<node* ,int>> q; // (node, horizontal distance)
    q.push(make_pair(root,0));
    map<int, int> m; // (horizontal distance, root -> data)

    while(!q.empty()){ // level order traversal
        pair<node*, int> p = q.front();

        node*  currentnode = p.first;
        int current_Horizontal_distance = p.second;

        q.pop();

        if(m.count(current_Horizontal_distance) == 0){
            m[current_Horizontal_distance] = currentnode -> data;
        }

        if(currentnode -> left != NULL){
            pair<node*, int> left = make_pair(currentnode->left, current_Horizontal_distance -1);
            q.push(left);
        }
        if(currentnode -> right != NULL){
            pair<node*, int> right = make_pair(currentnode->right, current_Horizontal_distance + 1);
            q.push(right);
        }
    }
    cout << "Top view of a tree = ";
    for(auto itr : m){
        cout << itr.second << " " ;
    }
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *  root = binarytree(preorder);

    topview(root);
    cout << endl;
    return 0;
}