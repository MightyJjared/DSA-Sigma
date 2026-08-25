#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// LeetCode 103: Binary Tree Zigzag Level Order Traversal
// Time Complexity: O(n), Space Complexity: O(n)

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

static int index = -1;

node* binarytree(vector<int> preorder) {
    index++;

    if (preorder[index] == -1) {
        return NULL;
    }

    node* root = new node(preorder[index]);

    root->left = binarytree(preorder);
    root->right = binarytree(preorder);

    return root;
}

vector<vector<int>> zigzagLevelOrder(node* root) {
    vector<vector<int>> result;

    if (root == NULL) {
        return result;
    }

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> current;

        for (int i = 0; i < size; i++) {
            node* currentNode = q.front();
            q.pop();

            current.push_back(currentNode->data);

            if (currentNode->left) {
                q.push(currentNode->left);
            }

            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }

        if (!leftToRight) {
            reverse(current.begin(), current.end());
        }

        result.push_back(current);

        leftToRight = !leftToRight;
    }

    return result;
}

int main() {
    vector<int> preorder = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };

    node* root = binarytree(preorder);

    vector<vector<int>> result = zigzagLevelOrder(root);

    for (vector<int> level : result) {
        for (int value : level) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}