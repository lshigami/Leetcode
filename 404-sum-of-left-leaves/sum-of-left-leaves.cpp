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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        int sum=0;
        if(!root->left && !root->right) return 0;
        q.push(root);
        while(!q.empty()){
            TreeNode*front =q.front();
            q.pop();
            if(front->left){
                if(front->left->left==nullptr && front->left->right==nullptr) {
                    sum+=front->left->val;
                    cout<<front->left->val<<" ";
                }
                q.push(front->left);
            }
            if(front->right) q.push(front->right);
        }
        return sum;
    }
};