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
    vector<TreeNode*>v;
public:
    void Inorder(TreeNode*root){
        if(root==nullptr) return;
        Inorder(root->left);
        v.push_back(root);
        Inorder(root->right);
    }
    TreeNode* MakeTree( int l, int r){
        if(l<=r){
            int m=(l+r)/2;
            TreeNode*root=v[m];
            root->left=MakeTree(l,m-1);
            root->right=MakeTree(m+1,r);
            return root;
        }
        else return nullptr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        Inorder(root);
        return MakeTree(0,v.size()-1);
    }
    
};