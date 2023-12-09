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
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>v;
       node(root,v);
        return v;
    }
private :
    void node(TreeNode*root,vector<int>&v){
        if(root){
            if(root->left!=nullptr)  node(root->left,v);
            v.push_back(root->val);
            if(root->right!=nullptr) node(root->right,v);
        }
    }
    
};