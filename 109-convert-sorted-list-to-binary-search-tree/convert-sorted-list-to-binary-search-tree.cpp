/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*>v;
        while(head){
            v.push_back(head);
            head=head->next;
        }
        return BuildTree(v,0,v.size()-1);
    }
private :
    TreeNode* BuildTree(vector<ListNode*>v, int l, int r){
        if(l>r) return nullptr;
        int m=(l+r)/2;
        TreeNode*root= new TreeNode{v[m]->val,BuildTree(v,l,m-1),BuildTree(v,m+1,r)};
        // root->val=v[m]->val;
        // root->left=BuildTree(v,l,m-1);
        // root->right=BuildTree(v,m+1,r);
        return root;
    }
};