class Solution {
public:
    void DFS(TreeNode* root,int max,int &ans)
    {
        if(root==NULL) return;
        if(root->val >= max){
            ans++;
            max = root->val;
        }
        DFS(root->left,max,ans);
        DFS(root->right,max,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        DFS(root,root->val,ans);
        return ans;
    }
};