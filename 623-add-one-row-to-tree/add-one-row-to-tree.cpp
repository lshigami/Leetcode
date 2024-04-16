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
    void DFS(TreeNode*root,int val,int i,int dep){
        if(root==nullptr) return;
        TreeNode*leftNode= new TreeNode(val,root->left,NULL);
        TreeNode*rightNode= new TreeNode(val,NULL,root->right);
        if(i==dep-1){
            root->left=leftNode;
            root->right=rightNode;
        }
        DFS(root->left,val,i+1,dep);
        DFS(root->right,val,i+1,dep);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*newnode= new TreeNode(val);
            newnode->left=root;
            root=newnode;
            return root;
        }
        DFS(root,val,1,depth);
        return root;
    }
};