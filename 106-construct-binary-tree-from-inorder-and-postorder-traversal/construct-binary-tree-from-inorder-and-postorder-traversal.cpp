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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int idx=n-1;
        for(int i=0;i<n;++i){
            m[inorder[i]]=i;
        }
        return BuildTree(inorder,postorder,0,n-1,idx);
    }
    TreeNode*BuildTree(vector<int>& inorder, vector<int>& postorder,int l,int r,int& idx){
        if(l>r) return nullptr;
        TreeNode*root= new TreeNode(postorder[idx--]);
        int Inidx=m[root->val];
        root->right=BuildTree(inorder,postorder,Inidx+1,r,idx);
        root->left=BuildTree(inorder,postorder,l,Inidx-1,idx);
        return root;
    }
};