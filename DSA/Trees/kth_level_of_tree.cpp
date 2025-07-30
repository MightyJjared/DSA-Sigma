#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

/*
This program builds a binary tree from a preorder input with -1 as null markers,
then prints all nodes at a given level 'k'.

Example input:
preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}

Constructed Tree:
        1
       / \
      2   3
         / \
        4   5

If k = 3, output will be: 4 5
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

void iteration(node* root, int k, int level){ 
    if(root == NULL){
        return;
    }
    if(k == level){
        cout << root -> data << " ";
    }
    iteration(root -> left, k, level+1);
    iteration(root -> right, k, level+1);
}

void kth1(node* root, int k){ // recursive approach
    iteration(root,k,1);
    cout << endl;
}
void kth2(node * root, int k){// level order
    if (root == NULL) {
        return;
    }
    queue<node*> q;
    int count = 1;

    q.push(root);
    q.push(NULL);

    while(q.size() != 0){
        node* temp = q.front();
        q.pop();
        if(temp == NULL && q.size() == 0){
            cout << endl;
            break;
        }
        if(temp == NULL){
            q.push(NULL);
            count++;
            continue;
        }
        if(count == k){
            cout << temp-> data << " ";
        }

        if(temp -> left != NULL){
            q.push(temp -> left);
        }
        if(temp -> right != NULL){
            q.push(temp -> right);
        }
    }

}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *  root = binarytree(preorder);
    kth1(root,3);
    return 0; 
}