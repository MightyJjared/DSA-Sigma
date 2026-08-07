#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using  namespace std;

// here we are doing iterative solutions rather than recursive approach
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


// here the trick is for preorder since the order is Root->Left->Right
// And we are using stack so we should first push Right then Left
void preorderIterative(node* rootnode){
    stack<node*> s;
    if(rootnode == NULL){
        return;
    }

    s.push(rootnode);

    while(s.size() != 0){
        node* currentnode = s.top();
        s.pop();

        cout << currentnode->data << " ";
        
        if(currentnode-> right != NULL){
            s.push(currentnode-> right);
        }

        if(currentnode-> left != NULL){
            s.push(currentnode-> left);
        }
    }
}

// it is a bit hard see strivers l10 video
void inorderIterative(node* root){
    stack<node*> s;
    if(root == NULL){
        return;
    }

    
    while(true){
        if(root != NULL){
            s.push(root);
            root = root -> left;
        }
        else{
            if(s.size() == 0){
                break;
            }
            root = s.top();
            s.pop();
            cout << root->data << " ";
            root = root -> right;
        }
    }
}

// see strivers l11 video
void postorderIterative(node* root){
    stack<node*> s1, s2;
    if(root == NULL){
        return;
    }
    
    s1.push(root);
    
    while(s1.size() != 0){
        node* currentnode = s1.top();
        s1.pop();
        s2.push(currentnode);
        
        if(currentnode->left != NULL){
            s1.push(currentnode->left);
        }
        if(currentnode->right != NULL){
            s1.push(currentnode->right);
        }
        
    }
    while(s2.size() != 0){
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main(){
    vector<int> order = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *  root = binarytree(order);
    preorderIterative(root);
    cout << endl;
    cout << "Hello";
    return 0; 
}