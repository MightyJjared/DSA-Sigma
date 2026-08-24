#include <iostream>
#include <queue>
#include <vector>
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

int transform(node* root){
    if(root == NULL){
        return 0;
    }
    int left_old = transform(root -> left);
    int right_old = transform(root -> right);

    int current_old = root -> data;

    root -> data = left_old + right_old;
    if(root -> left != NULL || root -> right != NULL){
        if(root -> left == NULL){
            root -> data += root -> right -> data;
        }
        else if(root -> right == NULL){
            root -> data += root -> left -> data;
        }
        else{
            root -> data += root -> left -> data + root -> right -> data;
        }
    }  
    return current_old;
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
    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *  root = binarytree(preorder);
    levelorder2(root);
    cout << endl;
    transform(root);
    levelorder2(root);
    cout << endl;
    return 0;
}