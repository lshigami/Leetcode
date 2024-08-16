/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       return DFS(root->left,root->right);
    }
    bool DFS(TreeNode*left,TreeNode*right){
        if(left==nullptr && right==nullptr ) return true;
        if(left==nullptr || right==nullptr ) return false;
        return left->val==right->val && DFS(left->left,right->right) && DFS(left->right,right->left);
    }
};