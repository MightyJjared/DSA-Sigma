#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this -> data = data;
        left = right = NULL;
    }
};

static int idx = -1;
node* binarytree(vector<int> vec){
    idx++;
    if(vec[idx] == -1){
        return NULL;
    }
    node* root = new node(vec[idx]);
    root -> left = binarytree(vec);
    root -> right = binarytree(vec);
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root -> right);
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    cout << endl;
    q.push(NULL);
    while(!q.empty()){
        node* current = q.front();
        q.pop();

        if(current == NULL){
            if(q.empty()){
                cout << endl;
                break;
            }
            cout << endl;
            q.push(NULL);
        }
        else{
            cout << current -> data << " ";
        if(current->left != NULL){
            q.push(current -> left);
        }
        if(current->right != NULL){
            q.push(current -> right);
        }
        }
    }
}

int height(node*root){
    if(root == NULL){
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root -> right);
    int current_height = max(left_height, right_height) + 1;
    return current_height;
}

int count(node*root){
    if(root == NULL){
        return 0;
    }
    int left_count = count(root->left);
    int right_count = count(root -> right);
    int current_count = left_count + right_count + 1;
    return current_count;
}

int sum(node*root){
    if(root == NULL){
        return 0;
    }
    int left_sum = sum(root->left);
    int right_sum = sum(root -> right);
    int current_sum = left_sum  + right_sum + root -> data;
    return current_sum;
}

int main(){
    vector<int> vec = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int size = vec.size();
    node* root = binarytree(vec);
    inorder(root);
    cout << endl;
    levelorder(root);
    cout << endl;
    cout << height(root);
    cout << endl;
    cout << count(root);
    cout << endl;
    cout << sum(root);
    cout << endl;
    return 0;
}
