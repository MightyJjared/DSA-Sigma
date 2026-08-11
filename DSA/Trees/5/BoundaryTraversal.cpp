#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
-----------------------------------------
COMPLEXITY ANALYSIS
-----------------------------------------

Let N = number of nodes
Let H = height of the tree

Time Complexity:

Leaf traversal       -> O(N)
Left boundary        -> O(H)
Right boundary       -> O(H)
Stack operations     -> O(H)

Total:
O(N) + O(H) + O(H)
= O(N)

Therefore:

Time Complexity = O(N)


Auxiliary Space:

Recursion stack      -> O(H)
Right boundary stack -> O(H)

Therefore:

Auxiliary Space = O(H)

Worst case (skewed tree):
H = N

Worst-case Auxiliary Space = O(N)

Output vector result = O(N)

If output space is included:

Total Space Complexity = O(N)
-----------------------------------------
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
public:

    // Add all leaf nodes from left to right
    // Time Complexity: O(N)
    // Space Complexity: O(H) due to recursion stack
    void leaf(Node* root, vector<int>& result) {

        if (root == NULL) {
            return;
        }

        // If current node is a leaf
        if (root->left == NULL && root->right == NULL) {
            result.push_back(root->data);
            return;
        }

        leaf(root->left, result);
        leaf(root->right, result);
    }


    vector<int> boundaryTraversal(Node* root) {

        vector<int> result;

        if (root == NULL) {
            return result;
        }

        // If root itself is a leaf
        if (root->left == NULL && root->right == NULL) {
            result.push_back(root->data);
            return result;
        }

        // Add root
        result.push_back(root->data);


        // -------------------------
        // LEFT BOUNDARY
        // -------------------------

        Node* l = root->left;

        // Time Complexity: O(H)
        while (l != NULL) {

            // Don't add leaf nodes here
            if (l->left != NULL || l->right != NULL) {
                result.push_back(l->data);
            }

            // Prefer left child
            if (l->left != NULL) {
                l = l->left;
            }
            // Otherwise go to right child
            else {
                l = l->right;
            }
        }


        // -------------------------
        // LEAF NODES
        // -------------------------

        // Time Complexity: O(N)
        leaf(root, result);


        // -------------------------
        // RIGHT BOUNDARY
        // -------------------------

        Node* r = root->right;

        stack<int> s;

        // Time Complexity: O(H)
        // Space Complexity: O(H)
        while (r != NULL) {

            // Don't add leaf nodes here
            if (r->left != NULL || r->right != NULL) {
                s.push(r->data);
            }

            // Prefer right child
            if (r->right != NULL) {
                r = r->right;
            }
            // Otherwise go to left child
            else {
                r = r->left;
            }
        }


        // Add right boundary in reverse order
        // Time Complexity: O(H)
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }


        return result;
    }
};


