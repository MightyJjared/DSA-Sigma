// leetcode 199
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;

        if(root == NULL){
            return result;
        }

        q.push(root);

        while(q.size() != 0){
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode* currentnode = q.front();
                q.pop();

                // Last node of this level
                if(i == levelSize - 1){
                    result.push_back(currentnode->val);
                }

                if(currentnode->left != NULL){
                    q.push(currentnode->left);
                }

                if(currentnode->right != NULL){
                    q.push(currentnode->right);
                }
            }
        }

        return result;
    }
};