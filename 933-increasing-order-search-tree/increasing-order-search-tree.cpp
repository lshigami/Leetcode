class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        TreeNode* newRoot = new TreeNode(v[0]);
        TreeNode* current = newRoot;
        for (int i = 1; i < v.size(); i++) {
            current->right = new TreeNode(v[i]);
            current = current->right;
        }
        return newRoot;
    }

private:
    void inorder(TreeNode* node, vector<int>& v) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
};
