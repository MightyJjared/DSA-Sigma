#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node* Binarytree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return NULL;
    }

    Node* root = new Node(nodes[idx]);
    root->left = Binarytree(nodes);
    root->right = Binarytree(nodes);

    return root;
}

void preorder(Node* Rootnode){
    if(Rootnode == NULL){
        return;
    }

    cout << Rootnode->data << " ";
    preorder(Rootnode->left);
    preorder(Rootnode->right);
}

void levelorder1(Node* rootnode){
    if(rootnode == NULL){
        return;
    }
    queue<Node*> q;
    q.push(rootnode);

    while(q.size() != 0){
        Node* root = q.front();
        q.pop();

        cout << root->data << " ";
        
        if(root->left != NULL){
            q.push(root->left);
        }

        if(root->right != NULL){
            q.push(root->right);
        }
    }
}


int main(){
    vector<int> nodes = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* Rootnode = Binarytree(nodes);
    preorder(Rootnode);
    return 0;
}