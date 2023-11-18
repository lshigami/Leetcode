class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            } else if (root->right == nullptr) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
};
