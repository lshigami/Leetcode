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
    vector<int> findMode(TreeNode* root) {
        map<int,int>m;
        Tranvers(root,m);
        vector<int>v;
        int MAX=INT_MIN;
        for(auto x:m){
            MAX=max(MAX,x.second);
        }
        for(auto x:m){
           if(x.second==MAX) v.push_back(x.first);
        }
        return v;
    }
private:
    void Tranvers(TreeNode*root, map<int,int>&m){
        if(root){
            Tranvers(root->left,m);
            m[root->val]++;
            Tranvers(root->right,m);
        }
    }
};