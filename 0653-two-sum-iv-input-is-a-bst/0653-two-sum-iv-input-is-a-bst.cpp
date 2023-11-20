class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return find(root, k, seen);
    }

private:
    bool find(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;
        
        if (seen.count(k - node->val)) return true;
        
        seen.insert(node->val);
        
        return find(node->left, k, seen) || find(node->right, k, seen); 
    }
};