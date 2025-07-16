#include <iostream>
using namespace std;

/*
🧠 LeetCode Question: 572. Subtree of Another Tree

Given the roots of two binary trees `root` and `subRoot`, 
return true if there is a subtree of `root` with the same structure 
and node values as `subRoot` and false otherwise.

A subtree of a binary tree `root` is a tree that consists of a node in `root` 
and all of this node's descendants.

Example:
Input:
    Tree root:       3
                    / \
                   4   5
                  / \
                 1   2

    Tree subRoot:    4
                    / \
                   1   2

Output: true ✅
*/

class node {
public:
    int data;
    node* right;
    node* left;

    node(int x) {
        data = x;
        right = left = NULL;
    }
};

bool isSameTree(node* p, node* q) {
    if (p == NULL || q == NULL) {
        return p == q;
    }
    bool isleftsame = isSameTree(p->left, q->left);
    bool isrightsame = isSameTree(p->right, q->right);
    return (isleftsame && isrightsame && (p->data == q->data));
}

bool isSubtree(node* root, node* subroot) {
    if (root == NULL || subroot == NULL) {
        return root == subroot;
    }
    if (root->data == subroot->data && isSameTree(root, subroot)) {
        return true;
    }
    bool left = isSubtree(root->left, subroot);
    bool right = isSubtree(root->right, subroot);
    return left || right;
}

int main() {
    // Create Tree root
    node* root = new node(3);
    root->left = new node(4);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(2);

    // Create Tree subroot
    node* subroot = new node(4);
    subroot->left = new node(1);
    subroot->right = new node(2);

    bool result = isSubtree(root, subroot);

    if (result) {
        cout << "subroot is a subtree of root" << endl;
    }
    else {
        cout << "subroot is NOT a subtree of root" << endl;
    }

    return 0;
}
