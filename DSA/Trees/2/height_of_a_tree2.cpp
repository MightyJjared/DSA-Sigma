#include <iostream>
#include <vector>
#include <queue>
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

int height(node* root){
    queue<node*> q;

    if(root == NULL){
        return 0;
    }

    int count = 0;

    q.push(root);
    q.push(NULL);

    while(q.size() != 0){

        node* currentnode = q.front();
        q.pop();

        if(currentnode == NULL && q.size() == 0){
            count = count + 1;
            return count;
        }

        if(currentnode == NULL){
            count = count + 1;
            q.push(NULL);
            continue;
        }

        if(currentnode->left != NULL){
            q.push(currentnode->left);
        }

        if(currentnode->right != NULL){
            q.push(currentnode->right);
        }
    }

    return count;
}

int main(){

    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    node* root = binarytree(preorder);

    cout << height(root) << endl;

    return 0;
}