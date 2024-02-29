class Solution {
public:
    unordered_map<int,int>m;
    bool DFS(TreeNode*root,int level){
        if(root==nullptr) return true;
        if(level&1){
            if(root->val&1) return false;
        }
        else {
            if(!(root->val&1)) return false;
        }
        if(m.find(level)!=m.end()){
            if(level&1) {
                if(m[level]<=root->val) return false;
            }
            else {
                if(m[level]>=root->val) return false;
            }
        }
        m[level]=root->val;
        return DFS(root->left,level+1) && DFS(root->right,level+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        return DFS(root,0);
    }
};
