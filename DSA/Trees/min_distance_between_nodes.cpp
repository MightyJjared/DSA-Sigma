#include <iostream>
#include <vector>
using  namespace std;

/*          1
          /   \
         2     3
        / \     \
       4   5     6
    
    here min distance bw n1 and n2 is the the number of edges between them, for example for (4,6) shortest path is
    4,2,1,3,6 and edges between them are 4 so outpust is 4.
    approach is min distance will always pass through lowest common ansector ie LCA so
    1 - we wil find lca by LCA function then we will individually find the distance from lca to n1, then lca to n2
    then we will add them and that will be our answer, here distance from lca to n is basically the program we wrote
    named path_to_a_node.cpp.
    time complexity = O(n) , space = O(1)
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

int static idx = -1;
node* binarytree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    node* root = new node(preorder[idx]);

    root -> left = binarytree(preorder);
    root -> right = binarytree(preorder);
    
    return root;
}

node* LCA(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    
    if(root -> data == n1 || root -> data == n2){
        return root;
    }
    
    node* left = LCA(root -> left,n1,n2);
    node* right = LCA(root -> right,n1,n2);

    if(left != NULL && right != NULL){
        return root;
    }

    if(left == NULL || right == NULL){
        if(left == right){
            return NULL;
        }
        if(left == NULL){
            return right;
        }
        else{
            return left;
        }
    }
}

int path(node* root, int n){
    if(root == NULL){
        return -1;
    }

    if(root -> data == n){
        return 0;
    }

    int left = path(root -> left, n);
    if(left != -1){
        return  left+1;
    }

    int right = path(root -> right, n);
    if(right != -1){
        return  right+1;
    }

    return -1;
}

int min_distance(node* root, int n1, int n2){
    node* lca = LCA(root,n1,n2);

    int left_distance = path(lca,n1);
    int right_distance = path(lca,n2);

    return left_distance + right_distance;
}

int main(){
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *  root = binarytree(preorder);

    cout << min_distance(root,4,6) << endl;
    return 0;
}