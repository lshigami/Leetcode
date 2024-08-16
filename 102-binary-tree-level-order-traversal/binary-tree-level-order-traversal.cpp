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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>v;
        if(root==nullptr) return v;
        q.push({root,0});
        int level=-1;
        while(!q.empty()){
            TreeNode*node=q.front().first;
            int levelParent=q.front().second;
            if(levelParent>level){
                v.push_back({node->val});
                level+=1;
            }
            else{
                v.back().push_back({node->val});
            }
            q.pop();
            if(node->left){
                q.push({node->left,levelParent+1});
            }
            if(node->right){
                q.push({node->right,levelParent+1});
            }
        }
        return v;
    }
};