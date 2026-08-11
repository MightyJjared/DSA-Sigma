#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    void helper(TreeNode* root,
                vector<pair<int, pair<int, int>>>& result,
                int row,
                int col) {

        if (root == NULL) {
            return;
        }

        // Store: {column, {row, node value}}
        result.push_back({col, {row, root->val}});

        // Left child: row + 1, column - 1
        helper(root->left, result, row + 1, col - 1);

        // Right child: row + 1, column + 1
        helper(root->right, result, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> FinalResult;
        vector<int> currentResult;

        if (root == NULL) {
            return FinalResult;
        }

        // Stores: {column, {row, value}}
        vector<pair<int, pair<int, int>>> result;

        helper(root, result, 0, 0);

        // Sorts by:
        // 1. Column
        // 2. Row
        // 3. Value
        sort(result.begin(), result.end());

        int size = result.size();

        int Col = result[0].first;

        for (int i = 0; i < size; i++) {

            int currentCol = result[i].first;
            int val = result[i].second.second;

            if (currentCol == Col) {
                currentResult.push_back(val);
            }
            else {
                FinalResult.push_back(currentResult);

                currentResult.clear();

                Col = currentCol;

                currentResult.push_back(val);
            }
        }

        // Add the last column
        FinalResult.push_back(currentResult);

        return FinalResult;
    }
};


// Time Complexity: O(N log N)
// DFS traversal takes O(N)
// Sorting N nodes takes O(N log N)
// Grouping the columns takes O(N)
//
// Overall: O(N log N)
//
// Space Complexity: O(N)
// The result vector stores all N nodes.
// Recursion stack takes O(H), where H is tree height.
// Overall auxiliary/storage space: O(N)


int main() {

    // Example tree:
    //
    //        3
    //       / \
    //      9   20
    //          / \
    //         15  7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> result = obj.verticalTraversal(root);

    // Print the result
    for (auto column : result) {
        cout << "[ ";

        for (int value : column) {
            cout << value << " ";
        }

        cout << "] ";
    }

    cout << endl;

    return 0;
}