#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
LeetCode Reference: 653 - Two Sum IV - Input is a BST
Time Complexity: O(n)
Space Complexity: O(n)
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

// Stores BST elements in sorted order using inorder traversal
void inorder(node* root, vector<int>& vec) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, vec);

    vec.push_back(root->data);

    inorder(root->right, vec);
}

// Finds whether two nodes have values whose sum is k
bool findTarget(node* root, int k) {
    vector<int> vec;

    inorder(root, vec);

    unordered_map<int, int> m;

    for (int i = 0; i < vec.size(); i++) {
        int currentval = vec[i];

        int remaining = k - currentval;

        // Check if the required complement was already seen
        if (m.find(remaining) == m.end()) {
            m[currentval] = 0;
        }
        else {
            return true;
        }
    }

    return false;
}

int main() {
    node* root = new node(5);

    root->left = new node(3);
    root->right = new node(6);

    root->left->left = new node(2);
    root->left->right = new node(4);

    root->right->right = new node(7);

    int k = 9;

    cout << findTarget(root, k) << endl;

    return 0;
}