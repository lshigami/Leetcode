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
    void DFS(TreeNode*root,int&sum,vector<int>&v){
        if(root==nullptr) return ;
        if(!root->left && !root->right){
            int temp=0;
            v.push_back(root->val);
            for(int i=0;i<v.size();i++){
                temp+=v[i]*pow(10,v.size()-1-i);
            }
            cout<<temp<<" ";
            sum+=temp;
        }
        else v.push_back(root->val);
        DFS(root->left,sum,v);
        DFS(root->right,sum,v);
        v.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        vector<int>v;
        DFS(root,sum,v);
        return sum;
    }
};