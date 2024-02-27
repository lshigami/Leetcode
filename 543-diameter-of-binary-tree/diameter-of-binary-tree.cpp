/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root) {
          Height(root);
         return ans;
         }
    int Height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        ans=max(leftHeight+rightHeight,ans);
        return max(leftHeight, rightHeight) + 1;
    }
};