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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>v;
        vector<int>res;
        queue<TreeNode*>q;
        if(root==nullptr) return res;
        else q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=1;i<=n;i++){
                TreeNode*node=q.front();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            v.push_back(temp);
        }
        for(auto x:v){
            res.push_back(x.back());
        }
        return res;
    }
};