#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree
*/

class node {
public:
    int data;
    node* left;
    node* right;

    node(int x) {
        data = x;
        left = right = NULL;
    }
};

static int idx = -1;

node* binarytree(vector<int> preorder) {
    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    node* root = new node(preorder[idx]);

    root->left = binarytree(preorder);
    root->right = binarytree(preorder);

    return root;
}

int helper(node* root) {
    if (root == NULL) {
        return 0;
    }

    int left = helper(root->left);
    int right = helper(root->right);

    int current_old = left + right + root->data;

    root->data = left + right;

    return current_old;
}

void toSumTree(node* root) {
    helper(root);
}

void levelorder(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;

            if (!q.empty()) {
                q.push(NULL);
            }

            continue;
        }

        cout << temp->data << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {
    vector<int> preorder = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };

    node* root = binarytree(preorder);

    cout << "Before transformation:" << endl;
    levelorder(root);

    toSumTree(root);

    cout << "After transformation:" << endl;
    levelorder(root);

    return 0;
}