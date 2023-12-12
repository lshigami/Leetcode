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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>pv;
        vector<int>qv;
        DFS(p,pv);
        DFS(q,qv);
        return pv==qv;
    }
private :
    void DFS(TreeNode*p,vector<int>&v){
       if(p==nullptr) {
           v.push_back(0);
           return;
       }
        v.push_back(p->val);
        DFS(p->left,v);
        DFS(p->right,v);
    }
};