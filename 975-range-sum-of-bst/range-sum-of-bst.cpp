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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        DFS(root,sum,low,high);
        return sum;
    }
    void DFS(TreeNode*root,int &sum,int l,int h){
        if(root){
            if(root->val <=h && root->val >=l) sum+=root->val;
            DFS(root->left,sum,l,h);
            DFS(root->right,sum,l,h);
        }
    }
};