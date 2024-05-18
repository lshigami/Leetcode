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
    int move;
    int DFS(TreeNode*root){
        if(root==nullptr) return 0;
        int left_value=DFS(root->left);
        int right_value=DFS(root->right);
        move+=abs(left_value)+abs(right_value);
        return root->val-1+left_value+right_value;
    }
    int distributeCoins(TreeNode* root) {
        move=0;
        DFS(root);
        return move;
    }
};