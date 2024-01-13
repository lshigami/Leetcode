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
    unordered_map<int,int>m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return BuildTree(preorder,inorder,0,n-1,idx);
    }
    TreeNode*BuildTree(vector<int>& pre, vector<int>& in,int l, int r,int& idx){
        if(l>r) return nullptr;
        TreeNode*root=new TreeNode(pre[idx++]);
        int Inidx=m[root->val];
        root->left=BuildTree(pre,in,l,Inidx-1,idx);
        root->right=BuildTree(pre,in,Inidx+1,r,idx);
        return root;
    }

};