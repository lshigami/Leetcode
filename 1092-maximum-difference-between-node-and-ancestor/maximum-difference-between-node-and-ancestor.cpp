/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //preorder traversal
    //time: o(n)
    //space: o(1)
    int maxAncestorDiff(TreeNode* root, int imax = INT_MIN, int imin = INT_MAX) {
        if(nullptr == root)
            return 0;
        
        //root
        imax = max(imax, root -> val);
        imin = min(imin, root -> val);
        v_max = max(v_max, abs(imax - imin));
        maxAncestorDiff(root -> left, imax, imin);//go to left child
        maxAncestorDiff(root -> right, imax, imin);//go to right child
        
        return v_max;  
    }    
private:
    int v_max = 0;
};