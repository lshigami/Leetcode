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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        Sum(root,ans,v,targetSum);
        return ans;
    }
    void Sum(TreeNode*root,vector<vector<int>>&ans,vector<int>&v,int target){
        if(root!=nullptr ){
            v.push_back(root->val);
            if(root->left==nullptr && root->right==nullptr && root->val==target){
                ans.push_back(v);
            }
            Sum(root->left,ans,v,target-root->val);
            Sum(root->right,ans,v,target-root->val);
            v.pop_back();
        }
    }

};