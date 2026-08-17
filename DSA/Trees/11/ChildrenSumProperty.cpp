#include <iostream>
using namespace std;

// Children Sum in a Binary Tree - GFG
// Time Complexity: O(N), where N is the number of nodes.
// Space Complexity: O(H), where H is the height of the tree due to recursion.

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
    bool helper(Node* root){
        if(root == NULL){
            return true;
        }

        if(root->left != NULL && root->right != NULL){
            if(root->left->data + root->right->data != root->data){
                return false;
            }
        }
        else if(root->left != NULL){
            if(root->left->data != root->data){
                return false;
            }
        }
        else if(root->right != NULL){
            if(root->right->data != root->data){
                return false;
            }
        }

        if(helper(root->left) == false || helper(root->right) == false){
            return false;
        }

        return true;
    }

    bool isSumProperty(Node* root) {
        if(helper(root) == false){
            return false;
        }
        return true;
    }
};

// Time Complexity: O(N), where N is the number of nodes.
// Space Complexity: O(H), where H is the height of the tree due to recursion.

int main() {

    // Creating the tree
    Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(6);

    Solution solution;

    if(solution.isSumProperty(root)){
        cout << "Tree satisfies Sum Property" << endl;
    }
    else{
        cout << "Tree does not satisfy Sum Property" << endl;
    }

    return 0;
}