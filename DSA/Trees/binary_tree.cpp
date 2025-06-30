#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

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

void preOrder(node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root -> left);
    preOrder(root-> right);

}

void inorder(node * root){
    if(root == NULL){
        return;
    }
    inorder(root ->left);
    cout << root -> data << " ";
    inorder(root ->right);
}

void postorder(node * root){
    if(root == NULL){
        return;
    }
    postorder(root ->left);
    postorder(root ->right);
    cout << root -> data << " ";
}

void levelorder1(node * root){
    if (root == NULL) {
        return;
    }
    queue<node*> q;

    q.push(root);

    while(q.size() != 0){
        node* temp = q.front();
        q.pop();

        cout << temp-> data << " ";

        if(temp -> left != NULL){
            q.push(temp -> left);
        }
        if(temp -> right != NULL){
            q.push(temp -> right);
        }
    }
}

void levelorder2(node * root){
    if (root == NULL) {
        return;
    }
    queue<node*> q;

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
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << temp-> data << " ";

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
    levelorder2(root);
    cout << endl;
    return 0; 
}