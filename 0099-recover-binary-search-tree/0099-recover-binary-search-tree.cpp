class Solution {
public:
    TreeNode *first, *second, *prev;
    
    void recoverTree(TreeNode* root) {
        first = second = prev = NULL;
        inorder(root);
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
};
