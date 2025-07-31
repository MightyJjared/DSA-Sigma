#include <iostream>
#include <vector>
using namespace std;

/*
    Question:
    Given the preorder traversal of a binary tree (with -1 representing NULL),
    build the binary tree and find the path from root to a specific node (say `target`).
    The path should be returned in the form of a vector<int>.
     
            1
          /   \
         2     3
        / \     \
       4   5     6

    Approach:
    1. Use recursive construction of the tree from preorder traversal.
    2. To find the path, do a DFS from the root:
       - If current node is NULL, return false.
       - Add current node's data to path vector.
       - If current node is the target, return true.
       - Recur on left and right. If either returns true, propagate true.
       - If both return false, backtrack by removing the last node from path and return false.
    3. At the end, path vector will contain root to target node path if it exists.
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

bool getPath(node* root, int target, vector<int>& path) {
    if (root == NULL) return false;

    path.push_back(root->data);

    if (root->data == target) return true;

    if (getPath(root->left, target, path) || getPath(root->right, target, path)) {
        return true;
    }

    path.pop_back(); // backtrack
    return false;
}

int main() {
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node* root = binarytree(preorder);

    int target = 6;
    vector<int> path;
    if (getPath(root, target, path)) {
        cout << "Path to node " << target << " = ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";}
        cout << endl;
    } else {
        cout << "Node not found in tree." << endl;
    }

    return 0;
}

