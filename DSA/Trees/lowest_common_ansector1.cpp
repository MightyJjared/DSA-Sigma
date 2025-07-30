#include <iostream>
#include <vector>
using  namespace std;

    /*
    This program constructs a binary tree from a given preorder traversal where -1 represents a NULL node. 
    Then, it finds the Lowest Common Ancestor (LCA) of two nodes by first finding the paths from the root to each node
    (using backtracking),storing those paths in vectors p1 and p2. The LCA is identified by comparing both paths from
    the beginning and tracking the last common value.
    For example, for the tree built from the vector {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1}, the structure is:

            1
          /   \
         2     3
        / \     \
       4   5     6

    If we find LCA(4,5), the paths are [1,2,4] and [1,2,5], so the LCA is 2. If we find LCA(4,6), the paths are [1,2,4]
    and [1,3,6], so the LCA is 1.
    The space complexity is O(n) due to the path vectors used in recursion.
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


bool path(node* root, vector<int> &p, int n){
    if(root == NULL){
        return false;
    }

    p.push_back(root -> data);

    if(root -> data == n){
        return true;
    }

    bool leftpath = path(root -> left, p, n);
    bool rightpath = path(root -> right, p, n);

    if(leftpath == true || rightpath == true){
        return true;
    }
    p.pop_back();
    return false;
}

int LCA1(node* root, int n1, int n2){//here logic is we will find the path for n1 and n2 from root seperatly using the
    vector<int> p1;                  // path function ie lets say n is 4 and path will be {1,2,4}for the given tree
    vector<int> p2;                  // after getting the two vectors or path the last common index elemnet in both
                                     // the vectors will be our LSA. 
    path(root, p1, n1);              // time = O(n), space = O(n)
    path(root, p2, n2);

    int lca = -1;

    for(int i =0, j =0; i < p1.size() && j < p2.size(); i++, j++){
        if(p1[i] == p2[j]){
            lca = p1[i];
        }
    }
    return lca;
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *  root = binarytree(preorder);
    cout << LCA1(root,4,5) << endl;
    return 0; 
}