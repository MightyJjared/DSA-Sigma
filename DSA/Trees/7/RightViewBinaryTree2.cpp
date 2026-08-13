while(q.size() != 0){
    TreeNode* node = q.front();
    q.pop();

    if(node == NULL && q.size() == 0){
        break;
    }

    if(node == NULL){
        q.push(NULL);
        continue;
    }

    TreeNode* Nextnode = q.front();

    if(Nextnode == NULL){
        result.push_back(node->val);
    }

    if(node->left != NULL){
        q.push(node->left);
    }

    if(node->right != NULL){
        q.push(node->right);
    }
}