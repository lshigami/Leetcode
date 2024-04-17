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
    unordered_map<int,string>m;
    void DFS(TreeNode*root,string s,vector<string>&res){
        if(root==nullptr) return;
        if(!root->left && !root->right){
            s+=m[root->val];
            res.push_back(s);
            return;
        }else{
            s+=m[root->val];
        }
        DFS(root->left,s,res);
        DFS(root->right,s,res);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        vector<string>res;
        char x='a';
        for(int i=0;i<26;i++){
            m[i]=string(1,x++);
        }
        DFS(root,s,res);
        string ans=res[0];
        for(auto &x:res){
            reverse(x.begin(),x.end());
        }
        return *min_element(res.begin(),res.end());
    }
};