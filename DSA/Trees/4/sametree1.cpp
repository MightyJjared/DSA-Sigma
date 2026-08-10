#include <iostream>
using namespace std;

/*
🧠 LeetCode Question: 100. Same Tree

Given the roots of two binary trees `p` and `q`, check if they are the same.

Two trees are the same if:
1. They have the same structure.
2. All corresponding node values are equal.

Example:
Input:
    Tree p:       1
                 / \
                2   3

    Tree q:       1
                 / \
                2   3

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
        if (p == q) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isleftsame = isSameTree(p->left, q->left);
    bool isrightsame = isSameTree(p->right, q->right);
    if (isleftsame == true && isrightsame == true && p->data == q->data) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    // Create Tree p
    node* p = new node(1);
    p->left = new node(2);
    p->right = new node(3);

    // Create Tree q
    node* q = new node(1);
    q->left = new node(2);
    q->right = new node(3);

    bool result = isSameTree(p, q);

    if (result) {
        cout << "Trees are the same" << endl;
    }
    else {
        cout << "Trees are different" << endl;
    }

    return 0;
}
