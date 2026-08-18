#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Time Complexity: O(N) average, where N is the number of nodes.
// Space Complexity: O(N), where N is the number of nodes.

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
    void helper(Node* root, int time, int &maxTime, unordered_map<Node* , Node*> &parent, unordered_map<Node*, bool> &visited){
        if(root == NULL){
            return;
        }
        
        if(visited[root] == true){
            return;
        }
        
        visited[root] = true;
        maxTime = max(time, maxTime);
        
        time = time + 1;
        
        //down
        helper(root->left, time, maxTime, parent, visited);
        helper(root->right, time, maxTime, parent, visited);
        
        //up
        helper(parent[root], time, maxTime, parent, visited);
    }

    int minTime(Node* root, int target) {
        unordered_map<Node* , Node*> parent;
        queue<Node*> q;
        Node* targetNode = NULL;

        if(root == NULL){ // edge case 1
            return 0;
        }

        q.push(root);

        // doing level order traversal and storing the parent of each root in a map
        while(q.size() != 0){
            Node* node = q.front();

            if(node->data == target){
                targetNode = node;
            }

            q.pop();

            if(node->left != NULL){
                q.push(node->left);
                parent[node->left] = node;
            }

            if(node->right != NULL){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
        
        int time = 0;
        int maxTime = 0;
        unordered_map<Node*, bool> visited;

        helper(targetNode, time, maxTime, parent, visited);

        return maxTime;
    }
};

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 2;

    Solution solution;

    cout << "Minimum time: " << solution.minTime(root, target) << endl;

    return 0;
}