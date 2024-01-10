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
#define ll long long
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        return sum(root,targetSum,0) + pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
    int sum(TreeNode*root,int target,ll now){
        if(root==nullptr) return 0;
        now+=root->val;
        return (now==target) + sum(root->left,target,now) + sum(root->right,target,now);
    }
};